/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:52:54 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/17 13:41:06 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	normalise_angle(float angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

float	distance_two_points(t_fpoint p, t_fpoint q)
{
	float	re;

	re = sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
	return (re);
}

bool	confirm_hit_x(float x_to_hit, float y_hit, float angle, t_vars *vars)
{
	if (x_to_hit < 0 || x_to_hit > vars->smap_width - 1 || y_hit < 0 || y_hit > vars->smap_height - 1)
		return (true);
	if (facing_right(angle) && (vars->smap[(int)x_to_hit][(int)y_hit] == '1'))
		return (true);
	else if (facing_left(angle) && (vars->smap[(int)x_to_hit -1][(int)(y_hit)] == '1'))
		return (true);
	return (false);
}

bool	confirm_hit_y(float x_hit, float y_to_hit, float angle, t_vars *vars)
{
	if (y_to_hit < 0 || y_to_hit > vars->smap_height - 1 || x_hit < 0 || x_hit > vars->smap_width - 1)
		return (true);
	if (facing_down(angle) && (vars->smap[(int)x_hit][(int)y_to_hit] == '1'))
		return (true);
	else if (facing_up(angle) && (vars->smap[(int)x_hit][(int)y_to_hit -1] == '1'))
		return (true);
	return (false);
}

//read confirm_hit_x as cofirm hit in x = const
//read confirm_hit_y as confirm hit in y = const
	// if (fabs(angle - 0.0) < 0.0001)
	// 	angle += 0.0001;
	// else if (fabs(angle - PI/2) < 0.0001)
	// 	angle += 0.0001;
	// else if (fabs(angle - PI) < 0.0001)
	// 	angle += 0.0001;
	// else if (fabs(angle - 3*PI/2) < 0.0001)
	// 	angle += 0.0001;
	// else if (fabs(angle - 2 * PI) < 0.0001)
	// 	angle += 0.0001;