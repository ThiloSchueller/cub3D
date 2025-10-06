/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:58 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/06 15:42:14 by tschulle         ###   ########.fr       */
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
				mlx_put_pixel(vars->background, x, y, vars->config->ceiling_color);
			else
				mlx_put_pixel(vars->background, x, y, vars->config->floor_color); //ADD OPACITY? so 0xffffffff, istead of 0xffffff
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

	x = 0;
	y = 0;
	while (x < vars->smap_width)
	{
		while (y < vars->smap_height)
		{
			if (vars->smap[x][y] == '1')
				mlx_put_pixel(vars->minimap, x , y , 0x00FF0055);
			else
				mlx_put_pixel(vars->minimap, x , y , 0xFFFFFF55);
			y++;
		}
		y = 0;
		x++;
	}
	render_minimap_view(vars);
	return (0);
}

int	render_walls(t_vars *vars)
{
	int	x;
	int y;
	int h;
	int	i;
	int j;

	i = 0;
	j = 0;
	x = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			mlx_put_pixel(vars->walls, i, j, 0x00000000);
			j++;
		}
		j = 0;
		i++;
	}
	while (x < WIDTH)
	{
		h = calculate_height(vars, x);
		y = HEIGHT / 2 - h / 2;
		while(y < HEIGHT / 2 + h / 2)
		{
			mlx_put_pixel(vars->walls, x, y, 0xFF00FFFF);
			y++;
		}
		x++;
	}
	//printf("%hhu\n", vars->images.east->pixels[1]);
	//mlx_put_pixel(vars->walls, 300, 400, vars->images.west->pixels[1800]);
	return (0);
}

int	render(t_vars *vars)
{
	render_background(vars);
	render_minimap(vars);
	render_walls(vars);
	return (0);
}