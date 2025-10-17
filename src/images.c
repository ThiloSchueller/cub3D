/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:38:01 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/17 13:43:20 by tschulle         ###   ########.fr       */
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
