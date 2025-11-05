/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:56:28 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/05 13:08:34 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	calculate_angle(t_vars *vars, int x)
{
	double	degree_per_pixel;
	double	angle_for_x;

	degree_per_pixel = (double)FOV / (double)WIDTH;
	angle_for_x = vars->view_angle + (FOV / 2 * PI / 180)
		- degree_per_pixel * x * PI / 180;
	return (angle_for_x);
}

t_hit_info	get_hit_info(t_vars *vars, int x)
{
	double		angle;
	t_hit_info	hit_info;

	angle = normalise_angle(calculate_angle(vars, x));
	hit_info = calculate_distance(vars, angle);
	hit_info.wall_height = (HEIGHT /  (hit_info.distance / SCALE)); //cos(angle -vars->view_angle)
	// if (hit_info.wall_height > 600) // this is wrong but preverts segfaults
	// 	hit_info.wall_height = 600;
	//hit_info.new_angle = angle;
	hit_info.texture = define_texture(vars, angle, hit_info.vertical_hit);
	return (hit_info);
}

t_hit_info	steep_angles(t_vars *vars, double angle)
{
	t_hit_info	hit_info;

	if (angle < PI / 4 || angle > PI / 4 * 7)
		hit_info = hit_right(vars, angle);
	else if (angle <  PI * 3 / 4)
		hit_info = hit_top(vars, angle);
	else if (angle < PI * 5 / 4)
		hit_info = hit_left(vars, angle);
	else
		hit_info = hit_bot(vars, angle);
	return (hit_info);
}

t_hit_info	calculate_distance(t_vars *vars, double angle)
{
	t_fpoint	ray_pos;
	t_fpoint	next;
	t_hit_info	hit_info;

	ray_pos = vars->fpos;
	if (fabs(fmod(angle, PI/2)) < EPSILON || fabs(fmod(angle, PI/2) - PI/2) < EPSILON)
	{
		hit_info = steep_angles(vars, angle);
		hit_info.distance = hit_info.distance * cos(angle - vars->view_angle);
		return (hit_info);
	}
	int i = 0;
	while (1)
	{
		next = lines_to_hit(ray_pos, angle);
		ray_pos = calc_intersections(vars, angle, next.x, next.y);
		//corner
		// if (ray_pos.x == next.x && ray_pos.y == next.y &&confirm_hit_y(ray_pos.x, ray_pos.y, angle, vars) && confirm_hit_x(ray_pos.x, ray_pos.y, angle, vars))
		// {
		// 	hit_info.vertical_hit = false;
		// 	hit_info.percent_of_hit = fmod(ray_pos.x, SCALE) / SCALE;
		// 	break ;
		// }
		// edge case of hitting crosses in the koordinaten
		// if (ray_pos.x == next.x && ray_pos.y == next.y &&confirm_hit_y(ray_pos.x, ray_pos.y, angle, vars))
		// {
		// 	hit_info.vertical_hit = false;
		// 	hit_info.percent_of_hit = fmod(ray_pos.x, SCALE) / SCALE;
		// 	printf("corner hit\n");
		// 	fflush(stdout);
		// 	break ;
		// }
		//again
		//herhehreheheheheheh
		if (ray_pos.x == next.x && confirm_hit_x(ray_pos.x, ray_pos.y, angle, vars))
		{
			hit_info.vertical_hit = true;
			hit_info.percent_of_hit = fmod(ray_pos.y, SCALE) / SCALE;
			break ;
		}
		else if (ray_pos.y == next.y && confirm_hit_y(ray_pos.x, ray_pos.y, angle, vars))
		{
			hit_info.vertical_hit = false;
			hit_info.percent_of_hit = fmod(ray_pos.x, SCALE) / SCALE;
			break ;
		}
		i++;
	}
	hit_info.distance = distance_two_points(vars->fpos, ray_pos);
	hit_info.distance = hit_info.distance * cos(angle - vars->view_angle);

	//printf("iterationcount is %d\n", i);
	return (hit_info);
}

t_fpoint	calc_intersections(t_vars *vars, double angle, double x_to_hit, double y_to_hit)
{
	double		c;
	double		m;
	double		x_hit;
	double		y_hit;
	double		distance_vertical;
	double		distance_horizontal;

	m = -tan(angle);
	if ( m == 0.0)
		m = 0.01;
	c = vars->fpos.y - (m * vars->fpos.x);
	x_hit = (y_to_hit - c) / m;
	y_hit = m * x_to_hit + c;
	distance_vertical = distance_two_points(vars->fpos, (t_fpoint){x_to_hit, y_hit});
	distance_horizontal = distance_two_points(vars->fpos, (t_fpoint){x_hit, y_to_hit});
	// if (distance_horizontal == distance_vertical)
	// {
	// 	printf("========================\n");
	// 	return ((t_fpoint){x_to_hit, y_to_hit});
	// }
	if (distance_horizontal < distance_vertical)
		return ((t_fpoint){x_hit, y_to_hit});
	else
		return ((t_fpoint){x_to_hit, y_hit});
}

// distance_vertical = read distance to vertical line
//distance_horizontal = distance to horizontal line
// if (fabs(angle - normalise_angle(vars->view_angle)) < 0.02)
// {
// 	printf("normalised angle is %f\n", angle);
// 	printf("estimated distance was %f\n", distance_two_points(vars->fpos, (t_fpoint){ray_pos.x, ray_pos.y}));
// 	printf("estimated hit point was x: %f\n", ray_pos.x);
// 	printf("estimated hit point was y: %f\n", ray_pos.y);
// 	printf("calculated Steigung is %f\n", m);
// 	printf("calculated distance is %f\n", hit_info.distance);
// 	printf("potential hit in x axis is %f\n", x_hit);
// 	printf("potential hit in y axis is %f\n", y_hit);
// 	printf("it is a vertical hit: %d\n", hit_info.vertical_hit);
// 	printf("distance horizontal would be %f\n", distance_horizontal);
// 	printf("distance vertical would be %f\n", distance_vertical);
// 	//if (!(y_to_hit < 0 || y_to_hit > vars->smap_height || x_hit < 0 || x_hit > vars->smap_width))
// 	//	printf("checking in point x %d and y %d is %c\n", (int)x_to_hit, (int)y_to_hit, vars->smap[(int)x_hit][(int)y_to_hit]);
// 	printf("---------------------------------------\n");
// 	printf("player pos  x is %f\n", vars->fpos.x);
// 	printf("player pos  y is %f\n", vars->fpos.y);
// 	printf("x to hit is: %f\n", x_to_hit);
// 	printf("y to his is: %f\n", y_to_hit);
// }
// if (fabs(m) > 1000)
// 	m = 1000;
// if (fabs(m) < 0.001)
// 	m = 0.001;
// // if (fabs(cos(angle)) < 0.1) // vertical ray
// //   m = 100; // or some large number
// // if (angle > 0.1 || angle > 2 * PI - 0.1)
// // 	m = 0.01;
