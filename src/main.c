/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:14:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/25 11:45:20 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	clean_after_x(t_vars *vars)
{
	mlx_delete_texture(vars->textures->east);
	mlx_delete_texture(vars->textures->west);
	mlx_delete_texture(vars->textures->north);
	mlx_delete_texture(vars->textures->south);
	mlx_delete_image(vars->mlx, vars->background);
	mlx_delete_image(vars->mlx, vars->minimap);
	mlx_delete_image(vars->mlx, vars->walls);
	ft_free_vars(vars);
	mlx_terminate(vars->mlx);
}

void	delete_texture_clean(t_vars *vars)
{
	if (vars->textures->east)
		mlx_delete_texture(vars->textures->east);
	if (vars->textures->west)
		mlx_delete_texture(vars->textures->west);
	if (vars->textures->north)
		mlx_delete_texture(vars->textures->north);
	if (vars->textures->south)
		mlx_delete_texture(vars->textures->south);
	ft_free_vars(vars);
}

void	init_after_mlx(t_vars *vars)
{
	vars->background = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->minimap = mlx_new_image(vars->mlx, WIDTH -30, HEIGHT -30);
	vars->walls = mlx_new_image (vars->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(vars->mlx, vars->background, 0, 0);
	mlx_image_to_window(vars->mlx, vars->minimap, 30, 30);
	mlx_image_to_window(vars->mlx, vars->walls, 0, 0);
	vars->background->instances->z = 1;
	vars->minimap->instances->z = 3;
	vars->walls->instances->z = 2;
}

void	call_mlx_function(t_vars *vars) //new_function_gain_place_in_main
{
	mlx_key_hook(vars->mlx, &ft_key_hook, vars);
	mlx_loop_hook(vars->mlx, &ft_loop_hook, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char *argv[])
{
	t_config	*data;
	t_vars		vars;

	data = check_arg_map(argc, argv);
	if (!data)
		return (1);
	vars.config = data;
	init_vars(&vars);
	vars.textures = malloc(sizeof(t_texture));
	if (!vars.textures)
		ft_exit(ERROR_MALLOC, &vars);
	if (ft_get_textures(&vars) < 0)
	{
		delete_texture_clean(&vars);
		return (1);
	}
	vars.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!vars.mlx)
		ft_exit(ERROR_MLX, &vars);
	init_after_mlx(&vars);
	call_mlx_function(&vars);
	clean_after_x(&vars);
	return (0);
}
