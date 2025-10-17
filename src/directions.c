/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:58:30 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/17 11:15:56 by tschulle         ###   ########.fr       */
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
