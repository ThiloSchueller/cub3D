/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:14:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/05 15:42:32 by tschulle         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int			fd;
	t_config	*data;
	t_vars	vars;

	fd = 0;
	data = check_arg_map(argc, argv);
	if (!data)
		return (1);
	vars.config = data;
	init_vars(&vars);
	vars.textures = malloc(sizeof(t_texture));
	if (!vars.textures)
		ft_exit(ERROR_MALLOC, &vars);
	vars.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!vars.mlx)
		ft_exit(ERROR_MLX, &vars);
	ft_get_textures(&vars);
	init_after_mlx(&vars);
	mlx_key_hook(vars.mlx, &ft_key_hook, &vars);
	mlx_loop_hook(vars.mlx, &ft_loop_hook, &vars);
	//render(&vars);
	mlx_loop(vars.mlx);
	clean_after_x(&vars);
}
