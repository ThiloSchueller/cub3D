/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:41:11 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/05 15:39:53 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void 	ft_free_vars(t_vars *vars)
{
	if (vars->config->map != NULL)
		ft_free_array(vars->config->map);
	if (vars->smap != NULL)
		ft_free_array(vars->smap);
	if (vars->cmap != NULL)
		ft_free_array(vars->cmap);
	if (vars->config->texture_ea != NULL)
		free(vars->config->texture_ea);
	if (vars->config->texture_we != NULL)
		free(vars->config->texture_we);
	if (vars->config->texture_no != NULL)
		free(vars->config->texture_no);
	if (vars->config->texture_so != NULL)
		free(vars->config->texture_so);
	if (vars->config != NULL)
		free(vars->config);
	if (vars->textures != NULL)
		free(vars->textures);
}


int	ft_exit(int code, t_vars *vars)
{
	if (code == ERROR_MLX)
		ft_putendl_fd("Error mlx\n", 2);
	if (code == ERROR_MALLOC)
		ft_putendl_fd("Error malloc\n", 2);
	ft_free_vars(vars);
	exit(code);
}