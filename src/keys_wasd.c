/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/09 14:31:36 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	w_key(t_vars *vars)
{
	double	dx;
	double	dy;

	dx = cos(vars->view_angle);
	dy = -sin(vars->view_angle);
	move_2d(vars, dx, dy);
}

void	s_key(t_vars *vars)
{
	double	dx;
	double	dy;

	dx = -cos(vars->view_angle);
	dy = sin(vars->view_angle);
	move_2d(vars, dx, dy);
}

void	d_key(t_vars *vars)
{
	double	dx;
	double	dy;

	dx = sin(vars->view_angle);
	dy = cos(vars->view_angle);
	move_2d(vars, dx, dy);
}

void	a_key(t_vars *vars)
{
	double	dx;
	double	dy;

	dx = -sin(vars->view_angle);
	dy = -cos(vars->view_angle);
	move_2d(vars, dx, dy);
}

void	move_2d(t_vars *vars, double dx, double dy)
{
	if (vars->smap[vars->pos.x][vars->pos.y + (int)copysign(1.0, dy)] != '1')
	//if (!confirm_hit_y(vars->fpos.x, vars->fpos.y + dx, normalise_angle(vars->view_angle), vars))
		vars->fpos.y += dy;
	if (vars->smap[vars->pos.x + (int)copysign(1.0, dx)][vars->pos.y] != '1')
	//if (!confirm_hit_x(vars->fpos.x + dx, vars->fpos.y, normalise_angle(vars->view_angle), vars))
		vars->fpos.x += dx;
	vars->pos.x = floor(vars->fpos.x);
	vars->pos.y = floor(vars->fpos.y);
}