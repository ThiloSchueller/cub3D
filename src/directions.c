/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:58:30 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/14 14:13:25 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	facing_right(float angle)
{
	if (angle < PI / 2 || angle >= 1.5 * PI)
		return (true);
	return (false);
}

bool	facing_left(float angle)
{
	if (angle >= PI / 2 && angle < 1.5 * PI)
		return (true);
	return (false);
}

bool	facing_up(float angle)
{
	if (angle < PI)
		return (true);
	return (false);
}

bool	facing_down(float angle)
{
	if (angle >= PI)
		return (true);
	return (false);
}

t_fpoint	lines_to_hit(t_fpoint point, float angle)
{
	t_fpoint	next;
	
	if (facing_up(angle))
	{
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
	}
	else
	{
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
	}
	return(next);
}
