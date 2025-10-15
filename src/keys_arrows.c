/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:27:45 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/15 16:43:01 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	left_key(t_vars *vars)
{
	vars->view_angle += PI / 180;
	vars->view_angle = normalise_angle(vars->view_angle);
}

void	right_key(t_vars *vars)
{
	vars->view_angle -= PI / 180;
	vars->view_angle = normalise_angle(vars->view_angle);
}
