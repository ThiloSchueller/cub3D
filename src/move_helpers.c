/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:14:06 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/06 17:14:59 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ox(double angle)
{
	return (-0.00001 * (2 * facing_right(angle) - 1));
}

double	oy(double angle)
{
	return (-0.00001 * (2 * facing_down(angle) - 1));
}

bool	confirm_move_x(
	double x_to_hit, double y_hit, double angle, t_vars *vars)
{
	if (x_to_hit < 0 || x_to_hit > vars->smap_width - 1
		|| y_hit < 0 || y_hit > vars->smap_height - 1)
		return (true);
	if (facing_right(angle) && (vars->cmap[(int)x_to_hit][(int)y_hit] == '1'))
		return (true);
	else if (facing_left(angle)
		&& (vars->cmap[(int)x_to_hit -1][(int)(y_hit)] == '1'))
		return (true);
	return (false);
}

bool	confirm_move_y(
	double x_hit, double y_to_hit, double angle, t_vars *vars)
{
	if (y_to_hit < 0 || y_to_hit > vars->smap_height - 1
		|| x_hit < 0 || x_hit > vars->smap_width - 1)
		return (true);
	if (facing_down(angle) && (vars->cmap[(int)x_hit][(int)y_to_hit] == '1'))
		return (true);
	else if (facing_up(angle)
		&& (vars->cmap[(int)x_hit][(int)y_to_hit -1] == '1'))
		return (true);
	return (false);
}
