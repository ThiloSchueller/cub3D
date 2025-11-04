/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:31:03 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/04 16:35:58 by tschulle         ###   ########.fr       */
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

t_fpoint vec_add(t_fpoint a, t_fpoint b)
{
	return ((t_fpoint){a.x + b.x, a.y + b.y});
}

void	ft_loop_hook(void *param)
{
	t_vars	*vars;
	t_fpoint	d;

	d.x = 0;
	d.y = 0;
	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
		left_key(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
		right_key(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
		d = vec_add(d, w_key(vars));
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
		d = vec_add(d, s_key(vars));
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		d = vec_add(d, a_key(vars));
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
		d = vec_add(d, d_key(vars));
	double len = sqrt(d.x * d.x + d.y * d.y);
	if (len > 0)
	{
		d.x /= len;
		d.y /= len;
	}
	if (d.x != 0 || d.y != 0)
		move_2d(vars, d);
	printf("x is %f, y is %f\n", d.x, d.y);
	render(vars);
}
