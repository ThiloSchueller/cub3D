/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:41:11 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/17 14:03:31 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void 	ft_free_vars(t_vars *vars)
{
	if (vars->smap != NULL)
		ft_free_array(vars->smap);
}


int	ft_exit(int code, t_vars *vars)
{
	if (code == ERROR_MLX)
		ft_putendl_fd("Error mlx\n", 2);
	if (code == ERROR_MALLOC)
		ft_putendl_fd("Error malloc\n", 2);
	ft_free_vars(vars);
	(void)vars;
	exit(code);
}