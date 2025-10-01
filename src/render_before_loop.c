/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_before_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:58 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/01 17:00:55 by tschulle         ###   ########.fr       */
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

char **calc_smap(t_vars *vars)
{
	char	**smap;
	int		x;
	int		y;

	x = 0;
	y = 0;
	vars->smap_width = SCALE * vars->config.map_width;
	vars->smap_height = SCALE * vars->config.map_height;
	smap = malloc(((SCALE * vars->config.map_height) + 1)* sizeof(char *));
	if (smap == NULL)
		return (NULL);
	while (x < vars->smap_width)
	{
		smap[x] = malloc((vars->smap_width + 1 )* sizeof(char));
		while (y < vars->smap_height)
		{
			if (vars->config.map[x / SCALE][y / SCALE] == 'E')
			{
				if (x % SCALE == ( SCALE / 2) && y % SCALE == (SCALE / 2))
				{
					smap[x][y] = 'E';
					vars->pos.x = x;
					vars->pos.y = y;
				}
				else
					smap[x][y] = '0';
			}
			else
				smap[x][y] = vars->config.map[x / SCALE][y / SCALE];
			y++;
		}
		smap[x][y] = '\0';
		y = 0;
		x++;
	}
	smap[x] = NULL;
	return (smap);
}

int	render_minimap(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->config.map_width = 5;
	vars->config.map_height = 5;
	vars->config.map = (char *[]){"11111", "10E01", "10001", "10001", "11111"};
	vars->smap = calc_smap(vars);
	while (x < vars->smap_width)
	{
		while (y < vars->smap_height)
		{
			if (vars->smap[x][y] == '1')
				mlx_put_pixel(vars->minimap, x , y , 0x00000055);
			else if (vars->smap[x][y] == 'E')
				mlx_put_pixel(vars->minimap, x , y , 0xFFFF00F0);
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

int	render_minimap_view(t_vars *vars)
{
	int	angle;

	angle = -60;
	while (angle < 60)
	{
		render_minimap_rays(vars, vars->view_angle + angle * PI / 180);
		angle += 1;
	}
	return (0);
}

int	render_minimap_rays(t_vars *vars, float angle)
{
	t_point	ray;
	double	x;
	double	y;
	double	dx;
	double	dy;

	dx = cos(angle);
	dy = -sin(angle);
	ray = vars->pos;
	x = ray.x;
	y = ray.y;
	while (ray.x < vars->smap_width - SCALE && ray.x >= SCALE &&
		ray.y < vars->smap_width - SCALE && ray.y >= SCALE)
	{
		mlx_put_pixel(vars->minimap, ray.x, ray.y, 0x000000FF);
		x += dx;
		y += dy;
		ray.x = floor(x);
		ray.y = floor(y);
	}
	return (0);
}