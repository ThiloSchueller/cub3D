/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:00:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/06 12:01:27 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3D.h"

int	render_minimap_view(t_vars *vars)
{
	int	angle;

	angle = -FOV/2;
	while (angle <= FOV/2)
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
	while ((vars->smap[ray.x][ray.y + (int)copysign(1.0, dy)] != '1') &&
	 (vars->smap[ray.x + (int)copysign(1.0, dx)][ray.y] != '1'))
	{
		mlx_put_pixel(vars->minimap, ray.x, ray.y, 0x00000055);
		x += dx;
		y += dy;
		ray.x = floor(x);
		ray.y = floor(y);
	}
	mlx_put_pixel(vars->minimap, vars->pos.x, vars->pos.y, 0xFF000055);
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
					smap[x][y] = '0'; //simplify
					vars->pos.x = x;
					vars->pos.y = y;
					vars->fpos.x = (float)x;
					vars->fpos.y = (float)y;
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
