#include "cub3D.h"

float	calculate_angle(t_vars *vars, int x)
{
	float	degree_per_pixel;
	float	angle_for_x;

	degree_per_pixel = (float)FOV / (float)WIDTH;
	angle_for_x = vars->view_angle + (FOV / 2 * PI / 180) -
		degree_per_pixel * x * PI / 180;
	return (angle_for_x);
}

float	calculate_distance(t_vars *vars, float angle)
{
	double	dx;
	double	dy;
	t_fpoint ray_pos;
	//double	distance;
	t_hit_info hit_info;

	ray_pos = vars->fpos;
	dx = cos(angle);
	dy = -sin(angle);
	while (1)
	{
		if ((vars->smap[(int)ray_pos.x][(int)ray_pos.y + (int)copysign(1.0, dy)] != '1') &&
				(vars->smap[(int)ray_pos.x + (int)copysign(1.0, dx)][(int)ray_pos.y] != '1'))
		{
			ray_pos.x += dx;
			ray_pos.y += dy;
		}
		else
			break;
	}
	// ray_pos.x += dx;
	// ray_pos.y += dy;
	hit_info = calc_hit(vars, angle, ray_pos);
	// angle = normalise_angle(angle);
	// printf("%f\n", angle);
	// printf("%f\n", tan(PI / 4));
	// distance = sqrt((ray_pos.x - vars->fpos.x) * (ray_pos.x - vars->fpos.x) 
	// 			+ (ray_pos.y - vars->fpos.y) * (ray_pos.y - vars->fpos.y));
				// + precise_hit(ray_pos, vars, dx, dy);
	return (hit_info.distance);
	//return (hit_info.distance * cos(angle -vars->view_angle)); //fisheye correction, but segaults becuase disctance get higher then HEIGHT but probably becuase of fault distance calc
}

int	calculate_height(t_vars *vars, int x)
{
	float	angle;
	float	distance;
	float	wall_height;

	angle = calculate_angle(vars, x);
	distance = calculate_distance(vars, angle);
	wall_height = (HEIGHT / distance);
	return ((int)wall_height);
}

t_hit_info	calc_hit(t_vars *vars, float angle, t_fpoint ray_pos)
{
	float	y_to_hit;
	float	x_to_hit;
	t_hit_info	hit_info;

	if (angle >= 0 && angle <PI)
	{
		y_to_hit = floor(ray_pos.y);
		if ( angle > PI/2)
			x_to_hit = floor(ray_pos.x);
		if (angle <= PI/2)
			x_to_hit = ceil(ray_pos.x);
	}
	else //if (angle >= PI && angle <= 2 * PI)
	{
		y_to_hit = ceil(ray_pos.y);
		if (angle < 3 / 2 * PI)
			x_to_hit = floor(ray_pos.x);
		if (angle >= 3 / 2 * PI)
			x_to_hit = ceil(ray_pos.x);
	}
	hit_info = calc_intersection(vars, angle, x_to_hit, y_to_hit);
	return (hit_info);
 }

float	normalise_angle(float angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

t_hit_info	calc_intersection(t_vars *vars, float angle, float x_to_hit, float y_to_hit)
{
	float	c;
	float	x_hit;
	float	y_hit;
	float	distance_vertical;
	float	distance_horizontal;
	t_hit_info	hit_info;

	c = vars->fpos.y / (tan(angle) * vars->fpos.x);
	x_hit = (y_to_hit - c) / tan (angle);
	y_hit = tan(angle) * x_to_hit + c;
	distance_vertical = distance_two_points(vars->fpos, (t_fpoint){y_to_hit, x_hit});
	distance_horizontal = distance_two_points(vars->fpos, (t_fpoint){x_to_hit, y_hit});
	if (distance_vertical > distance_horizontal)
	{
		hit_info.distance = distance_vertical;
		hit_info.vertical_hit = true;
		hit_info.percent_of_hit = fmod(x_hit, 1);
	}
	else
	{
		hit_info.distance = distance_horizontal;
		hit_info.vertical_hit = false;
		hit_info.percent_of_hit = fmod(y_hit, 1);
	}
	return(hit_info);
}







//  float	precise_hit(t_fpoint ray_pos, t_vars *vars, float dx, float dy)
//  {
// 	float	re;
// 	if (vars->view_angle > 3 / 2 * PI && vars->view_angle < 2 * PI) //soll gar nicht um view angle ghen sonder um ray angle
// 	{
// 		re = quadrant4(ray_pos, vars, dx, dy);
// 	}
// 	return(re);
//  }

float	distance_two_points(t_fpoint p, t_fpoint q)
{
	float re;

	re = sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
	return (re);
}

// float	quadrant4(t_fpoint ray_pos, t_vars *vars, float dx, float dy)
// {
// 	float corrected = 0;
// 	float factor;
// 	float distance;

// 	(void) vars;
// 	distance = distance_two_points(ray_pos, (t_fpoint){ray_pos.x + dx, ray_pos.y +dy});
// 	factor = (floor(ray_pos.x + dx) - ray_pos.x) / dx;
// 	if (factor > 0)
// 		corrected = factor * distance;
// 	printf("%f\n", corrected);
// 	return (corrected);
// }