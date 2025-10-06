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
	double	distance;

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
	distance = sqrt((ray_pos.x - vars->fpos.x) * (ray_pos.x - vars->fpos.x) 
				+ (ray_pos.y - vars->fpos.y) * (ray_pos.y - vars->fpos.y));
				// + precise_hit(ray_pos, vars, dx, dy);
	return (distance);
	//return (distance * cos(angle -vars->view_angle)); //fisheye correction, but segaults becuase disctance get higher then HEIGHT but probably becuase of fault distance calc
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

//  float	precise_hit(t_fpoint ray_pos, t_vars *vars, float dx, float dy)
//  {
// 	float	re;
// 	if (vars->view_angle > 3 / 2 * PI && vars->view_angle < 2 * PI) //soll gar nicht um view angle ghen sonder um ray angle
// 	{
// 		re = quadrant4(ray_pos, vars, dx, dy);
// 	}
// 	return(re);
//  }

// float	distance_two_points(t_fpoint p, t_fpoint q)
// {
// 	float re;

// 	re = sqrt((q.x - p.x) * (q.x - p.x) + (q.y - q.y) * (q.y - q.y));
// 	return (re);
// }

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