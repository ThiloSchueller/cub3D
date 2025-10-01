/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:31:03 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/01 16:32:46 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	hook_minimap(mlx_key_data_t keydata, t_vars *vars)
// {

// }

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	//hook_minimap(keydata, param);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		vars->view_angle += PI / 18;
		render_minimap(vars);
	}
		if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		vars->view_angle -= PI / 18;
		render_minimap(vars);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		//free;
		mlx_terminate(vars->mlx);
		exit(EXIT_SUCCESS);
	} 
}

// mlx_is_key_down()