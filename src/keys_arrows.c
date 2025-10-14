/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:27:45 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/14 10:47:26 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	left_key(t_vars *vars)
{
	vars->view_angle += PI / 180;
}

void	right_key(t_vars *vars)
{
	vars->view_angle -= PI / 180;
}