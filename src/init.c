/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:02:54 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/22 15:15:44 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int	init_vars(t_vars *vars)
{
	vars->mmswitch = false;
	vars->smap_width = SCALE * vars->config->map_width;
	vars->smap_height = SCALE * vars->config->map_height;
	vars->scale = get_scaling_minimap(vars);
	vars->smap = calc_smap(vars);
	if (vars->smap == NULL)
		ft_exit(ERROR_MALLOC, vars);
	vars->background = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->minimap = mlx_new_image(vars->mlx, WIDTH -30, HEIGHT -30);
	vars->walls = mlx_new_image (vars->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(vars->mlx, vars->background, 0, 0);
	mlx_image_to_window(vars->mlx, vars->minimap, 30, 30);
	mlx_image_to_window(vars->mlx, vars->walls, 0, 0);
	set_view_angle(vars);
	vars->background->instances->z = 1;
	vars->minimap->instances->z = 3;
	vars->walls->instances->z = 2;
	return (0);
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
