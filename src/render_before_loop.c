/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_before_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:58 by tschulle          #+#    #+#             */
/*   Updated: 2025/09/30 16:52:12 by tschulle         ###   ########.fr       */
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
	int	x;
	int	y;
	int	scale;

	scale = 10;
	x = 0;
	y = 0;
	vars->config.map_width = 5;
	vars->config.map_height = 5;
	vars->config.map = (char *[]){"11111", "10E01", "10001", "10001", "11111"};
	while (x < vars->config.map_width * scale)
	{
		while (y < vars->config.map_height * scale)
		{
			if (vars->config.map[x/scale][y/scale] == '1')
				mlx_put_pixel(vars->minimap, x , y , 0x00000055);
			else if (vars->config.map[x/scale][y/scale] == 'E')
				mlx_put_pixel(vars->minimap, x , y , 0xFFFF00F0);
			else
				mlx_put_pixel(vars->minimap, x , y , 0xFFFFFF55);
			y++;
		}
		y = 0;
		x++;
		render_minimap_rays(vars);
	}
	return (0);
}

int	render_minimap_rays(t_vars *vars)
{

}