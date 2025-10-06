/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:38:01 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/06 14:09:50 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_textures(t_vars *vars)
{
	vars->textures->east = mlx_load_png(vars->config->texture_ea);
	vars->textures->west = mlx_load_png(vars->config->texture_we);
	vars->textures->south = mlx_load_png(vars->config->texture_so);
	vars->textures->north = mlx_load_png(vars->config->texture_no);
}


void	ft_textures_to_images(t_texture *textures, t_vars *vars) //need an extra image??
{
	vars->images.east = mlx_texture_to_image(vars->mlx, textures->east);
	vars->images.west = mlx_texture_to_image(vars->mlx, textures->west);
	vars->images.south = mlx_texture_to_image(vars->mlx, textures->south);
	vars->images.north = mlx_texture_to_image(vars->mlx, textures->north);
}