/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:14:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/17 14:36:35 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int argc, char *argv[])
{
	int			fd;
	t_config	*data;

	fd = 0;
	data = NULL;
	data = malloc(sizeof(t_config));
	if (!data)
	{
		perror("malloc");
		return (1);
	}
	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	fd = check_file(argv[1]);
	if (fd < 0)
	{
		free(data);
		return (1);
	}
	else if (fd > 2)
	{
		init_data(data);
		parser(fd, data, argv[1]);
		if (data->stop != 0)
		{
			printf("Invalid file.cub\n");
			free_data(data);
			return (1);
		}
	}
	t_vars	vars;
	vars.textures = malloc(sizeof(t_texture));
	vars.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!vars.mlx)
		ft_exit(ERROR_MLX, &vars);
	vars.config = data;
	ft_get_textures(&vars);
	mlx_key_hook(vars.mlx, &ft_key_hook, &vars);
	mlx_loop_hook(vars.mlx, &ft_loop_hook, &vars);
	init_vars(&vars);
	render(&vars);
	mlx_loop(vars.mlx);
	//mlx_terminate(vars.mlx);
}
