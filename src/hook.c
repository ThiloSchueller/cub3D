/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:31:03 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/21 14:54:32 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(vars->mlx);
		//free;
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
	{
		if (vars->mmswitch == true)
		{
			vars->minimap->instances->z = 0;
			vars->mmswitch = false;
		}
		else
		{
			vars->minimap->instances->z = 3;
			vars->mmswitch = true;
		}
	}
}

void	ft_loop_hook(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
		left_key(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
		right_key(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
		w_key(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
		s_key(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		a_key(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
		d_key(vars);
	render(vars);
}
