/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:15:29 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/06 14:50:45 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_fpoint	lines_to_hit_up(t_fpoint point, double angle)
{
	t_fpoint	next;

	next.y = floor(point.y);
	if (next.y == point.y)
		next.y -= 1;
	if (facing_left(angle))
	{
		next.x = floor(point.x);
		if (next.x == point.x)
			next.x -= 1;
	}
	else
	{
		next.x = ceil(point.x);
		if (next.x == point.x)
			next.x += 1;
	}
	return (next);
}

t_fpoint	lines_to_hit_down(t_fpoint point, double angle)
{
	t_fpoint	next;

	next.y = ceil(point.y);
	if (next.y == point.y)
	{
		next.y += 1;
	}
	if (facing_left(angle))
	{
		next.x = floor(point.x);
		if (next.x == point.x)
			next.x -= 1;
	}
	else
	{
		next.x = ceil(point.x);
		if (next.x == point.x)
			next.x += 1;
	}
	return (next);
}

t_fpoint	lines_to_hit(t_fpoint point, double angle)
{
	t_fpoint	next;

	if (facing_up(angle))
		next = lines_to_hit_up(point, angle);
	else
		next = lines_to_hit_down(point, angle);
	return (next);
}

// t_fpoint lines_to_hit(t_fpoint point, double angle)
// {
// 	t_fpoint	next;
// 	if (facing_up(angle))
// 		next.y = floor(point.y - 0.000001);
// 	else
// 		next.y = ceil(point.y + 0.000001);
// 	if (facing_left(angle))
// 		next.x = floor(point.x - 0.000001);
// 	else
// 		next.x = ceil(point.x + 0.000001);
// return next;
// }
// bool	forbidden_square(t_vars *vars,double dx,double dy, double angle)
// {
// 	t_fpoint	fnewpos;
// 	t_point		newpos;
// 	t_fpoint	next;

// 	angle = normalise_angle(angle);
// 	next = lines_to_hit(vars->fpos, angle);
// 	// (void)angle;
// 	fnewpos.x = vars->fpos.x + dx;
// 	fnewpos.y = vars->fpos.y + dy;
// 	newpos.x = (int)fnewpos.x;
// 	newpos.y = (int)fnewpos.y;
// 	if ((vars->smap[newpos.x][newpos.y] == '0') &&
// 		(vars->smap[newpos.x + 1][newpos.y] == '0') &&
// 		(vars->smap[newpos.x][newpos.y + 1] == '0') &&
// 		(vars->smap[newpos.x + 1][newpos.y + 1] == '1'))
// 	{
// 		return (true);
// 	}
// 	return (false);
// }