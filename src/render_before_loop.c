/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_before_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:58 by tschulle          #+#    #+#             */
/*   Updated: 2025/09/30 16:12:05 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_background(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x < WIDTH)
	{
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(vars->background, x, y, 0xFFFFFF);
			else
				mlx_put_pixel(vars->background, x, y, 177000);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int	render_minimap(t_vars *vars)
{
	(void)vars;
	// int	x;
	// int	y;
	// int	scale;

	// scale = 5;
	// x = 0;
	// y = 0;
	// while (x < width * scale)
	// {
	// 	while (y < height * scale)
	// 	{
	// 		if (value(y/scale) == wall)
	// 			mlx_put_pixel(vars->minimap, x , 0 , 0x00000055);
	// 		else if (value == player)
	// 			mlx_put_pixel(vars->minimap, x , 0 , 0xFF000055);
	// 		else
	// 			mlx_put_pixel(vars->minimap, x , 0 , 0xFFFFFF55);
	// 		y++;
	// 	}
	// 	y = 0;
	// 	x++;
	// }
	return (0);
}