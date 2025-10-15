/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/15 11:49:30 by tschulle         ###   ########.fr       */
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
	move_2d(vars, dx, dy, vars->view_angle - PI /2);
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
	// dx = dx/2;
	// dy = dy/2;
	// float	y_to_hit;
	// float	x_to_hit;
	t_fpoint	next;

	angle = normalise_angle(angle);
	next = lines_to_hit(vars->fpos, angle);
	// if (facing_up(angle))
	// {
	// 	y_to_hit = floor(vars->fpos.y);
	// 	if (facing_left(angle))
	// 		x_to_hit = floor(vars->fpos.x);
	// 	else
	// 		x_to_hit = ceil(vars->fpos.x);
	// }
	// else
	// {
	// 	y_to_hit = ceil(vars->fpos.y);
	// 	if (facing_left(angle))
	// 		x_to_hit = floor(vars->fpos.x);
	// 	else
	// 		x_to_hit = ceil(vars->fpos.x);
	// }
	// if ((!confirm_hit_x(next.x, vars->fpos.y + dy -1, angle, vars) && angle < PI) ||
	// 	(!confirm_hit_x(next.x, vars->fpos.y + dy +1, angle, vars) && angle > PI))
	// 	vars->fpos.y += dy;
	// else if (angle < PI)
	// 	vars->fpos.y = floor(vars->fpos.y);
	// else
	// 	vars->fpos.y = ceil(vars->fpos.y);
	// if ((!confirm_hit_y(vars->fpos.x + dx +1, next.y, angle, vars) && (angle < PI /2 || angle > 1.5 * PI)) ||
	// 	(!confirm_hit_y(vars->fpos.x + dx -1, next.y, angle, vars) && (angle > PI /2 && angle < 1.5 * PI)))
	// 	vars->fpos.x += dx;
	// else if (angle < PI /2 || angle > 1.5 * PI)
	// 	vars->fpos.x = ceil(vars->fpos.x);
	// else
	// 	vars->fpos.x = floor(vars->fpos.x);
	// vars->pos.x = floor(vars->fpos.x);
	// vars->pos.y = floor(vars->fpos.y);
	if ((!confirm_hit_x(next.x, vars->fpos.y + dy -1, angle, vars) && facing_up(angle)) ||
		(!confirm_hit_x(next.x, vars->fpos.y + dy +1, angle, vars) && facing_down(angle)))
		vars->fpos.y += dy;
	// else if (facing_up(angle))
	// 	vars->fpos.y = floor(vars->fpos.y);
	// else
	// 	vars->fpos.y = ceil(vars->fpos.y);
	if ((!confirm_hit_y(vars->fpos.x + dx +1, next.y, angle, vars) && facing_right(angle)) ||
		(!confirm_hit_y(vars->fpos.x + dx -1, next.y, angle, vars) && facing_left(angle)))
		vars->fpos.x += dx;
	// else if (facing_right(angle))
	// 	vars->fpos.x = ceil(vars->fpos.x);
	// else
	// 	vars->fpos.x = floor(vars->fpos.x);
	vars->pos.x = floor(vars->fpos.x);
	vars->pos.y = floor(vars->fpos.y); //important for minimap but maybe unprecise
}