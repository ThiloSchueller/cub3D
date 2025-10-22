/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:14:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/22 13:12:26 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

t_config	*check_arg(int argc)
{
	t_config	*data;

	data = NULL;
	data = malloc(sizeof(t_config));
	if (!data)
	{
		perror("malloc");
		return (NULL);
	}
	if (argc != 2)
	{
		free(data);
		printf("Invalid arguments\n");
		return (NULL);
	}
	return (data);
}

int	check_file(char *file)
{
	char	*str;
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	str = ".cub";
	while (file[i])
		i++;
	i = i - 4;
	j = ft_memcmp(&file[i], str, 4);
	if (j != 0)
	{
		printf("Invalid file\n");
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Couldn't open file\n");
		return (-1);
	}
	return (fd);
}

t_config	*check_arg_map(int argc, char *argv[])
{
	int	fd;
	t_config	*data;

	data = check_arg(argc);
	if (!data)
		return (NULL);
	fd = check_file(argv[1]);
	if (fd > 2)
	{
		init_data(data);
		parser(fd, data, argv[1]);
		if (data->stop != 0)
		{
			printf("Invalid file.cub\n");
			free_data(data);
			return (NULL);
		}
	}
	else
		return (NULL);
	return (data);
}


int	main(int argc, char *argv[])
{
	int			fd;
	t_config	*data;

	fd = 0;
	data = check_arg_map(argc, argv);
	if (!data)
		return (1);
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
