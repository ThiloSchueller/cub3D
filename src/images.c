/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:38:01 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/25 11:44:52 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_textures(t_vars *vars)
{
	vars->textures->east = mlx_load_png(vars->config->texture_ea);
	vars->textures->west = mlx_load_png(vars->config->texture_we);
	vars->textures->south = mlx_load_png(vars->config->texture_so);
	vars->textures->north = mlx_load_png(vars->config->texture_no);
	free(vars->config->texture_ea);
	free(vars->config->texture_we);
	free(vars->config->texture_so);
	free(vars->config->texture_no);
	vars->config->texture_ea = NULL;
	vars->config->texture_we = NULL;
	vars->config->texture_so = NULL;
	vars->config->texture_no = NULL;
	if (!vars->textures->east || !vars->textures->west ||
			!vars->textures->south || !vars->textures->north)
		return (-1);
	return (1);
}
