/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:00:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/15 16:32:09 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_minimap_view(t_vars *vars)
{
	int	angle;

	angle = -FOV/2;
	while (angle <= FOV/2)
	{
		render_minimap_ray(vars, vars->view_angle + angle * PI / 180);
		angle += 1;
	}
	return (0);
}

int	render_minimap_ray(t_vars *vars, float angle)
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
	vars->smap_width = SCALE * vars->config->map_width;
	vars->smap_height = SCALE * vars->config->map_height;
	smap = malloc(((vars->smap_width) + 1)* sizeof(char *)); //protect
	if (smap == NULL)
		return (NULL);
	while (x < vars->smap_width)
	{
		smap[x] = malloc((vars->smap_height + 1 )* sizeof(char));  //protect
		while (y < vars->smap_height)
		{
			if (is_player_char(vars->config->map[y / SCALE][x / SCALE]) == true)
			{
				if (x % SCALE == ( SCALE / 2) && y % SCALE == (SCALE / 2))
				{
					
					smap[x][y] = '0'; //simplify
					vars->pos.x = x;
					vars->pos.y = y;
					vars->fpos.x = (float)x+ 0.0001;
					vars->fpos.y = (float)y+ 0.0001;
				}
				else
					smap[x][y] = '0';
			}
			else
				smap[x][y] = vars->config->map[y / SCALE][x / SCALE];
			y++;
		}
		smap[x][y] = '\0';
		y = 0;
		x++;
	}
	smap[x] = NULL;
	return (smap);
}


// char **calc_smap(t_vars *vars)
// {
// 	char	**smap;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	vars->smap_width = SCALE * vars->config->map_width;
// 	vars->smap_height = SCALE * vars->config->map_height;
// 	smap = malloc(((vars->smap_height) + 1)* sizeof(char *)); //protect
// 	if (smap == NULL)
// 		return (NULL);
// 	while (i < vars->smap_height)
// 	{
// 		smap[i] = malloc((vars->smap_width + 1 )* sizeof(char));  //protect
// 		while (j < vars->smap_width)
// 		{
// 			// printf("y is %d\n", y);
// 			// printf("x is %d\n", x);
// 			if (is_player_char(vars->config->map[i / SCALE][j / SCALE]) == true)
// 			{
// 				if (i % SCALE == ( SCALE / 2) && j % SCALE == (SCALE / 2))
// 				{
					
// 					smap[i][j] = '0'; //simplify
// 					vars->pos.x = j;
// 					vars->pos.y = i;
// 					vars->fpos.x = (float)j+ 0.0001;
// 					vars->fpos.y = (float)i+ 0.0001;
// 					printf("playerpos is x = %f and y = %f\n", vars->fpos.x, vars->fpos.y);
// 				}
// 				else
// 					smap[i][j] = '0';
// 			}
// 			else
// 				smap[i][j] = vars->config->map[i / SCALE][j / SCALE];
// 			j++;
// 		}
// 		smap[i][j] = '\0';
// 		j = 0;
// 		i++;
// 	}
// 	smap[i] = NULL;
// 	i = 0;
// 	j = 0;
// 	while (i < vars->smap_height)
// 	{
// 		while (j < vars->smap_width)
// 		{
// 			printf("%c", smap[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		j=0;
// 		i++;
// 	}
// 	return (smap);
// }


// char **calc_smap(t_vars *vars)
// {
// 	char	**smap;
// 	int		x;
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	vars->smap_width = SCALE * vars->config->map_width;
// 	vars->smap_height = SCALE * vars->config->map_height;
// 	smap = malloc(((vars->smap_height) + 1)* sizeof(char *)); //protect
// 	if (smap == NULL)
// 		return (NULL);
// 	while (x < vars->smap_width)
// 	{
// 		smap[x] = malloc((vars->smap_width + 1 )* sizeof(char));  //protect
// 		while (y < vars->smap_height)
// 		{
// 			// printf("y is %d\n", y);
// 			// printf("x is %d\n", x);
// 			if (is_player_char(vars->config->map[x / SCALE][y / SCALE]) == true)
// 			{
// 				if (x % SCALE == ( SCALE / 2) && y % SCALE == (SCALE / 2))
// 				{
					
// 					smap[x][y] = '0'; //simplify
// 					vars->pos.x = x;
// 					vars->pos.y = y;
// 					vars->fpos.x = (float)x+ 0.0001;
// 					vars->fpos.y = (float)y+ 0.0001;
// 				}
// 				else
// 					smap[x][y] = '0';
// 			}
// 			else
// 				smap[x][y] = vars->config->map[x / SCALE][y / SCALE];
// 			y++;
// 		}
// 		smap[x][y] = '\0';
// 		y = 0;
// 		x++;
// 	}
// 	smap[x] = NULL;
// 	return (smap);
// }
