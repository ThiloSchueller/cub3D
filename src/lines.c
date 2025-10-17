/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:15:29 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/17 11:19:37 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_fpoint	lines_to_hit_up(t_fpoint point, float angle)
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

t_fpoint	lines_to_hit_down(t_fpoint point, float angle)
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

t_fpoint	lines_to_hit(t_fpoint point, float angle)
{
	t_fpoint	next;

	if (facing_up(angle))
		next = lines_to_hit_up(point, angle);
	else
		next = lines_to_hit_down(point, angle);
	return (next);
}
