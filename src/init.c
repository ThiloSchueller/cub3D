/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:02:54 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/05 15:20:48 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_view_angle(t_vars *vars)
{
	if (vars->config->player_dir == 'E')
		vars->view_angle = 0.0;
	if (vars->config->player_dir == 'N')
		vars->view_angle = PI / 2;
	if (vars->config->player_dir == 'W')
		vars->view_angle = PI;
	if (vars->config->player_dir == 'S')
		vars->view_angle = 1.5 * PI;
}

char	**calc_cmap(t_vars *vars)
{
	char	**cmap;
	int		x;
	int		y;

	x = 0;
	y = 0;
	cmap = malloc(((vars->smap_width) + 1) * sizeof(char *));
	if (cmap == NULL)
		return (NULL);
	while (x < vars->smap_width)
	{
		cmap[x] = malloc((vars->smap_height + 1) * sizeof(char));
		if (cmap[x] == NULL)
			return (ft_free_array(cmap), NULL);
		while (y < vars->smap_height)
		{
			if (vars->smap[x][y] == '0' && 
				(vars->smap[x -1][y] == '1' ||
					vars->smap[x+1][y] == '1' ||
					vars->smap[x][y-1] == '1' ||
					vars->smap[x][y+1] == '1' ||
					vars->smap[x+1][y+1] == '1' ||
					vars->smap[x+1][y-1] == '1' ||
					vars->smap[x-1][y+1] == '1' ||
					vars->smap[x-1][y-1] == '1'))
				cmap[x][y] = '1';
			else
				cmap[x][y] = vars->smap[x][y];
			y++;
		}
		cmap[x][y] = '\0';
		y = 0;
		x++;
	}
	cmap[x] = NULL;
	return (cmap);
}

void	init_vars(t_vars *vars)
{
	vars->textures = NULL;
	vars->smap = NULL;
	vars->cmap = NULL;
	vars->mmswitch = false;
	vars->smap_width = SCALE * vars->config->map_width;
	vars->smap_height = SCALE * vars->config->map_height;
	vars->scale = get_scaling_minimap(vars);
	vars->smap = calc_smap(vars);
	if (vars->smap == NULL)
		ft_exit(ERROR_MALLOC, vars);
	vars->cmap = calc_cmap(vars);
	if (vars->cmap == NULL)
		ft_exit(ERROR_MALLOC, vars);
	set_view_angle(vars);
}

void	init_data(t_config *data)
{
	data->stop = 0;
	data->map_before = 0;
	data->no_set = 0;
	data->so_set = 0;
	data->we_set = 0;
	data->ea_set = 0;
	data->floor_set = 0;
	data->ceil_set = 0;
	data->map_set = 0;
	data->texture_no = NULL;
	data->texture_so = NULL;
	data->texture_we = NULL;
	data->texture_ea = NULL;
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->x_position = -1;
	data->y_position = -1;
	data->player_dir = '\0';
}

void	free_data(t_config *data)
{
	if (data->texture_no)
		free(data->texture_no);
	if (data->texture_so)
		free(data->texture_so);
	if (data->texture_ea)
		free(data->texture_ea);
	if (data->texture_we)
		free(data->texture_we);
	if (data->map)
		free_map(data->map);
	free(data);
}
