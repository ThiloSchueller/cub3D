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

t_hit_info	calculate_distance(t_vars *vars, float angle)
{
	double	dx;
	double	dy;
	t_fpoint ray_pos;
	//double	distance;
	t_hit_info hit_info;

	ray_pos = vars->fpos;
	dx = cos(angle);
	dy = -sin(angle);
	while (1) //if (vars->smap[(int)ray_pos.x][(int)ray_pos.y] != '1') 
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
	angle = normalise_angle(angle);
	hit_info = calc_hit(vars, angle, ray_pos);
	// if (fabs(angle - normalise_angle(vars->view_angle)) < 0.02)
	// {
	// 	printf("normalised angle is %f\n", angle);
	// 	printf("estimated distance was %f\n", distance_two_points(vars->fpos, (t_fpoint){ray_pos.x, ray_pos.y}));
	// 	printf("estimated hit point was x: %f\n", ray_pos.x);
	// 	printf("estimated hit point was y: %f\n", ray_pos.y);
	// 	//printf("the value is %c \n", vars->smap[79][20]);
	// }
	// printf("%f\n", tan(PI / 4));
	// distance = sqrt((ray_pos.x - vars->fpos.x) * (ray_pos.x - vars->fpos.x) 
	// 			+ (ray_pos.y - vars->fpos.y) * (ray_pos.y - vars->fpos.y));
				// + precise_hit(ray_pos, vars, dx, dy);
	return (hit_info);
	//return (hit_info.distance * cos(angle -vars->view_angle)); //fisheye correction, but segaults becuase disctance get higher then HEIGHT but probably becuase of fault distance calc
}

int	calculate_height(t_vars *vars, int x)
{
	float	angle;
	t_hit_info hit_info;
	float	wall_height;

	angle = calculate_angle(vars, x);
	hit_info = calculate_distance(vars, angle);
	wall_height = (HEIGHT /  hit_info.distance); //cos(angle -vars->view_angle)
	if (wall_height > 600)
		wall_height = 600;
	return ((int)wall_height);
}

t_hit_info	calc_hit(t_vars *vars, float angle, t_fpoint ray_pos)
{
	float	y_to_hit;
	float	x_to_hit;
	t_hit_info	hit_info;

	if (angle >= 0 && angle <= PI)
	{
		y_to_hit = floor(ray_pos.y);
		if (angle >= PI / 2)
			x_to_hit = floor(ray_pos.x);
		else
			x_to_hit = ceil(ray_pos.x);
	}
	else
	{
		y_to_hit = ceil(ray_pos.y);
		if (angle <= 1.5 * PI)
			x_to_hit = floor(ray_pos.x);
		else
			x_to_hit = ceil(ray_pos.x);
	}
	// if (fabs(angle - normalise_angle(vars->view_angle)) < 0.02)
	// {
	// 	printf("---------------------------------------\n");
	// 	printf("player pos  x is %f\n", vars->fpos.x);
	// 	printf("player pos  y is %f\n", vars->fpos.y);
	// 	printf("x to hit is: %f\n", x_to_hit);
	// 	printf("y to his is: %f\n", y_to_hit);
	// }

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
	float	m;
	float	x_hit;
	float	y_hit;
	float	distance_vertical;
	float	distance_horizontal;
	t_hit_info	hit_info;
	hit_info.vertical_hit = true;

	m = -tan(angle);
	// if (fabs(cos(angle)) < 0.1) // vertical ray
  	//   m = 100; // or some large number
	// if (angle > 0.1 || angle > 2 * PI - 0.1)
	// 	m = 0.01;
	c = vars->fpos.y - (m * vars->fpos.x);
	x_hit = (y_to_hit - c) / m;
	y_hit = m * x_to_hit + c;
	distance_vertical = distance_two_points(vars->fpos, (t_fpoint){x_to_hit, y_hit});
	distance_horizontal = distance_two_points(vars->fpos, (t_fpoint){x_hit, y_to_hit});
	if ((distance_horizontal <= distance_vertical) && confirm_hit_x(x_to_hit, y_hit, normalise_angle(angle), vars)) //maybe <=
		hit_info.distance = distance_horizontal;
	else if (distance_horizontal <= distance_vertical)
	 	hit_info.distance = distance_vertical;
	if ((distance_horizontal > distance_vertical) && confirm_hit_y(x_hit, y_to_hit, normalise_angle(angle), vars))
	 	hit_info.distance = distance_vertical;
	else if (distance_horizontal > distance_vertical)
	 	hit_info.distance = distance_horizontal;
	if (fabs(angle - normalise_angle(vars->view_angle)) < 0.02)
	{
		// printf("calculated Steigung is %f\n", m);
		// printf("calculated distance is %f\n", hit_info.distance);
		// printf("potential hit in x axis is %f\n", x_hit);
		// printf("potential hit in y axis is %f\n", y_hit);
		// printf("it is a vertical hit: %d\n", hit_info.vertical_hit);
		//printf("distance horizontal would be %f\n", distance_horizontal);
		//printf("distance vertical would be %f\n", distance_vertical);
		if (!(y_to_hit < 0 || y_to_hit > vars->smap_height || x_hit < 0 || x_hit > vars->smap_width))
			printf("checking in point x %d and y %d is %c\n", (int)x_hit, (int)y_to_hit, vars->smap[(int)x_hit][(int)y_to_hit]);
	}
	return(hit_info);
}

float	distance_two_points(t_fpoint p, t_fpoint q)
{
	float re;

	re = sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
	return (re);
}

bool	confirm_hit_x(float x_to_hit,float y_hit,float angle, t_vars *vars)
{
	if (x_to_hit < 0 || x_to_hit > vars->smap_width - 1 || y_hit < 0 || y_hit > vars->smap_height - 1)
	 	return (true);
	if ((angle <= 0.5 * PI || angle >= 1.5 * PI) && (vars->smap[(int)x_to_hit - 1][(int)y_hit] == '1')) 
		return (true);
	else if ((angle <= 1.5 * PI && angle >= 0.5 * PI) && (vars->smap[(int)x_to_hit][(int)(y_hit)] == '1'))
		return (true);
	return (false);
}
bool	confirm_hit_y(float x_hit,float y_to_hit,float angle, t_vars *vars)
{
	if (y_to_hit < 0 || y_to_hit > vars->smap_height - 1 || x_hit < 0 || x_hit > vars->smap_width - 1)
	 	return (true);
	// printf("%f\n", y_to_hit);
	// printf("%f\n", x_hit);
	if (angle >= PI &&(vars->smap[(int)x_hit][(int)y_to_hit - 1] == '1'))
		return (true);
	else if (angle <= PI && (vars->smap[(int)x_hit][(int)y_to_hit] == '1'))
		return (true);
	return (false);
}
