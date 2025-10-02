/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:41:11 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/02 13:46:08 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_exit(int code, t_vars *vars)
{
	if (code == ERROR_MLX)
		ft_putendl_fd("Error\n", 2);
	//free here
	(void)vars;
	exit(code);
}