/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:38:01 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/02 17:54:48 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_textures(t_texture *textures)
{
	textures->east = mlx_load_png("./textures/east.png");
	textures->west = mlx_load_png("./textures/west.png");
	textures->south = mlx_load_png("./textures/south.png");
	textures->north = mlx_load_png("./textures/north.png");
}


void	ft_textures_to_images(t_texture *textures, t_vars *vars) //need an extra image??
{
	vars->images.east = mlx_texture_to_image(vars->mlx, textures->east);
	vars->images.west = mlx_texture_to_image(vars->mlx, textures->west);
	vars->images.south = mlx_texture_to_image(vars->mlx, textures->south);
	vars->images.north = mlx_texture_to_image(vars->mlx, textures->north);
}