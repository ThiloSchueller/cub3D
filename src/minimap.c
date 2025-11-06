/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:00:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/06 15:32:35 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_fpoint	get_scaling_minimap(t_vars *vars)
{
	t_fpoint	scale;

	scale.x = 1;
	scale.y = 1;
	if (vars->smap_width > MMSIZE)
		scale.x = MMSIZE / vars->smap_width;
	if (vars->smap_height > MMSIZE)
		scale.y = MMSIZE / vars->smap_height;
	return (scale);
}

int	render_minimap_view(t_vars *vars)
{
	int	angle;

	angle = - (FOV / 2);
	while (angle <= FOV / 2)
	{
		render_minimap_ray(vars, vars->view_angle + angle * PI / 180);
		angle += 1;
	}
	return (0);
}

int	render_minimap_ray(t_vars *vars, double angle)
{
	t_point	ray;
	double	x;
	double	y;
	double	dx;
	double	dy;

	angle = normalise_angle(angle);
	dx = cos(angle);
	dy = -sin(angle);
	ray = vars->pos;
	x = ray.x;
	y = ray.y;
	while ((vars->smap[ray.x][ray.y + (int)copysign(1.0, dy)] != '1') &&
		(vars->smap[ray.x + (int)copysign(1.0, dx)][ray.y] != '1'))
	{
		mlx_put_pixel(vars->minimap, vars->scale.x
			* ray.x, vars->scale.y * ray.y, 0x00000055);
		x += dx;
		y += dy;
		ray.x = floor(x);
		ray.y = floor(y);
	}
	mlx_put_pixel(vars->minimap, vars->scale.x
		* vars->pos.x, vars->scale.y * vars->pos.y, 0xFF000055);
	return (0);
}

void	fill_smap(t_vars *vars, int x, int y, char ***smap)
{
	if (is_player_char(vars->config->map[y / SCALE][x / SCALE]) == true)
	{
		if (x % SCALE == (SCALE / 2) && y % SCALE == (SCALE / 2))
		{
			vars->pos.x = x;
			vars->pos.y = y;
			vars->fpos.x = (double)x + 0.5;
			vars->fpos.y = (double)y + 0.5;
		}
		(*smap)[x][y] = '0';
	}
	else
		(*smap)[x][y] = vars->config->map[y / SCALE][x / SCALE];
}

char	**calc_smap(t_vars *vars)
{
	char	**smap;
	int		x;
	int		y;

	x = 0;
	y = 0;
	smap = malloc(((vars->smap_width) + 1) * sizeof(char *));
	if (smap == NULL)
		return (NULL);
	while (x < vars->smap_width)
	{
		smap[x] = malloc((vars->smap_height + 1) * sizeof(char));
		if (smap[x] == NULL)
			return (ft_free_array(smap), NULL);
		while (y < vars->smap_height)
		{
			fill_smap(vars, x, y, &smap);
			y++;
		}
		smap[x][y] = '\0';
		y = 0;
		x++;
	}
	smap[x] = NULL;
	return (smap);
}

// int i = 0;
// int j  = 0;
// while (i < vars->smap_width)
// {
// 	while (j < vars->smap_height)
// 	{
// 		printf("%c", smap[i][j]);
// 		j++;
// 	}
// 	printf("\n");
// 	j=0;
// 	i++;
// }