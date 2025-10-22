/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/22 16:12:57 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	w_key(t_vars *vars)
{
	double	dx;
	double	dy;

	dx = cos(vars->view_angle);
	dy = -sin(vars->view_angle);
	move_2d(vars, dx, dy, vars->view_angle);
}

void	s_key(t_vars *vars)
{
	double	dx;
	double	dy;

	dx = -cos(vars->view_angle);
	dy = sin(vars->view_angle);
	move_2d(vars, dx, dy, vars->view_angle + PI);
}

void	d_key(t_vars *vars)
{
	double	dx;
	double	dy;

	dx = sin(vars->view_angle);
	dy = cos(vars->view_angle);
	move_2d(vars, dx, dy, vars->view_angle - PI / 2);
}

void	a_key(t_vars *vars)
{
	double	dx;
	double	dy;

	dx = -sin(vars->view_angle);
	dy = -cos(vars->view_angle);
	move_2d(vars, dx, dy, vars->view_angle + PI / 2);
}


void	move_2d(t_vars *vars, double dx, double dy, float angle)
{
	t_fpoint	next;

	angle = normalise_angle(angle);
	next = lines_to_hit(vars->fpos, angle);
	// if (forbidden_square(vars, dx, dy, angle))
	//  	return ;
	if ((!confirm_hit_x(floor(vars->fpos.x), vars->fpos.y + dy +1, angle, vars)
			&& facing_up(angle))
		|| (!confirm_hit_x(floor(vars->fpos.x), vars->fpos.y + dy +1, angle, vars)
			&& facing_down(angle)))
		vars->fpos.y += dy;
	else if (facing_down(angle))
		vars->fpos.y = ceil(vars->fpos.y) - 0.001;
	else 
		vars->fpos.y = floor(vars->fpos.y) + 0.001;
	if ((!confirm_hit_y(vars->fpos.x + dx +1, ceil(vars->fpos.y), angle, vars)
			&& facing_right(angle))
		|| (!confirm_hit_y(vars->fpos.x + dx -1, floor(vars->fpos.y), angle, vars)
			&& facing_left(angle)))
		vars->fpos.x += dx;
	else if (facing_right(angle))
		vars->fpos.x = ceil(vars->fpos.x) - 0.001;
	else
		vars->fpos.x = floor(vars->fpos.x) + 0.001;
	vars->pos.x = floor(vars->fpos.x);
	vars->pos.y = floor(vars->fpos.y);
	if (fabs(angle - normalise_angle(vars->view_angle)) < 0.02)
	{
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
	printf("player pos  x is %f\n", vars->fpos.x);
	printf("player pos  y is %f\n", vars->fpos.y);
// 	printf("x to hit is: %f\n", x_to_hit);
// 	printf("y to his is: %f\n", y_to_hit);
	}
}
//important for minimap but maybe unprecise , run into west wall, last lines