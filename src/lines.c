/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:15:29 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/22 15:45:40 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_fpoint lines_to_hit(t_fpoint point, float angle)
{
	t_fpoint	next;

	if (facing_up(angle))
		next.y = floor(point.y - 0.0001);
	else
		next.y = ceil(point.y + 0.0001);
	if (facing_left(angle))
		next.x = floor(point.x - 0.0001);
	else
		next.x = ceil(point.x + 0.0001);
return next;
}

bool	forbidden_square(t_vars *vars,float dx,float dy, float angle)
{
	t_fpoint	fnewpos;
	t_point		newpos;
	t_fpoint	next;

	angle = normalise_angle(angle);
	next = lines_to_hit(vars->fpos, angle);
	// (void)angle;
	fnewpos.x = vars->fpos.x + dx;
	fnewpos.y = vars->fpos.y + dy;
	newpos.x = (int)fnewpos.x;
	newpos.y = (int)fnewpos.y;
	if ((vars->smap[newpos.x][newpos.y] == '0') &&
		(vars->smap[newpos.x + 1][newpos.y] == '0') &&
		(vars->smap[newpos.x][newpos.y + 1] == '0') &&
		(vars->smap[newpos.x + 1][newpos.y + 1] == '1'))
	{
		printf("yes\n");
		if ((!confirm_hit_x(next.x, vars->fpos.y + dy -1, angle, vars)
				&& facing_up(angle))
			|| (!confirm_hit_x(next.x+2, vars->fpos.y + dy +1, angle, vars)
				&& facing_down(angle)))
			vars->fpos.y += dy;
		else if (facing_down(angle))
			vars->fpos.y = ceil(vars->fpos.y) - 0.001;
		else 
			vars->fpos.y = floor(vars->fpos.y) + 0.001;
		if ((!confirm_hit_y(vars->fpos.x + dx +1, next.y, angle, vars)
				&& facing_right(angle))
			|| (!confirm_hit_y(vars->fpos.x + dx -1, next.y+2, angle, vars)
				&& facing_left(angle)))
			vars->fpos.x += dx;
		else if (facing_right(angle))
			vars->fpos.x = ceil(vars->fpos.x) - 0.001;
		else
			vars->fpos.x = floor(vars->fpos.x) + 0.001;

		
		//if ((vars->fpos.x == ceil(vars->fpos.x) - 0.001) && (vars->fpos.y == ceil(vars->fpos.y) - 0.001))
		// {
		// 	vars->fpos.x = ceil(vars->fpos.x) - 0.001;
		// 	vars->fpos.y = ceil(vars->fpos.y) - 0.001;
		// }
		return (true);
	}
	return (false);
}

// t_fpoint	lines_to_hit_up(t_fpoint point, float angle)
// {
// 	t_fpoint	next;

// 	next.y = floor(point.y);
// 	if (next.y == point.y)
// 		next.y -= 1;
// 	if (facing_left(angle))
// 	{
// 		next.x = floor(point.x);
// 		if (next.x == point.x)
// 			next.x -= 1;
// 	}
// 	else
// 	{
// 		next.x = ceil(point.x);
// 		if (next.x == point.x)
// 			next.x += 1;
// 	}
// 	return (next);
// }

// t_fpoint	lines_to_hit_down(t_fpoint point, float angle)
// {
// 	t_fpoint	next;

// 	next.y = ceil(point.y);
// 	if (next.y == point.y)
// 	{
// 		next.y += 1;
// 	}
// 	if (facing_left(angle))
// 	{
// 		next.x = floor(point.x);
// 		if (next.x == point.x)
// 			next.x -= 1;
// 	}
// 	else
// 	{
// 		next.x = ceil(point.x);
// 		if (next.x == point.x)
// 			next.x += 1;
// 	}
// 	return (next);
// }

// t_fpoint	lines_to_hit(t_fpoint point, float angle)
// {
// 	t_fpoint	next;

// 	if (facing_up(angle))
// 		next = lines_to_hit_up(point, angle);
// 	else
// 		next = lines_to_hit_down(point, angle);
// 	return (next);
// }