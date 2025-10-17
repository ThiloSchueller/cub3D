/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/17 11:28:32 by tschulle         ###   ########.fr       */
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
	if ((!confirm_hit_x(next.x, vars->fpos.y + dy -1, angle, vars)
			&& facing_up(angle))
		|| (!confirm_hit_x(next.x, vars->fpos.y + dy +1, angle, vars)
			&& facing_down(angle)))
		vars->fpos.y += dy;
	if ((!confirm_hit_y(vars->fpos.x + dx +1, next.y, angle, vars)
			&& facing_right(angle))
		|| (!confirm_hit_y(vars->fpos.x + dx -1, next.y, angle, vars)
			&& facing_left(angle)))
		vars->fpos.x += dx;
	vars->pos.x = floor(vars->fpos.x);
	vars->pos.y = floor(vars->fpos.y);
}
//important for minimap but maybe unprecise , run into west wall, last lines