/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:14:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/09 15:10:45 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

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

void	init_data(t_config *data)
{
	data->stop = 0;
	data->no_set = 0;
	data->so_set = 0;
	data->we_set = 0;
	data->ea_set = 0;
	data->floor_set = 0;
	data->ceil_set = 0;
	data->map_set = 0;
	data->texture_no = NULL;
	data->texture_so = NULL;
	data->texture_we = NULL;
	data->texture_ea = NULL;
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->x_position = -1;
	data->y_position = -1;
	data->player_dir = '\0';
}

void	free_data(t_config *data)
{
	if (data->texture_no)
		free(data->texture_no);
	if (data->texture_so)
		free(data->texture_so);
	if (data->texture_ea)
		free(data->texture_ea);
	if (data->texture_we)
		free(data->texture_we);
	if (data->map)
		free_map(data->map);
	free(data);
}

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
	//t_texture textures;
	vars.textures = malloc(sizeof(t_texture));
	vars.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!vars.mlx)
		ft_exit(ERROR_MLX, &vars);
	vars.config = data;
	ft_get_textures(&vars);
	ft_textures_to_images(vars.textures, &vars);
	mlx_key_hook(vars.mlx, &ft_key_hook, &vars);
	mlx_loop_hook(vars.mlx, &ft_loop_hook, &vars);
	init_vars(&vars);
	render(&vars);
	mlx_loop(vars.mlx);
	//mlx_terminate(vars.mlx);
}

int	init_vars(t_vars * vars)
{
	vars->smap = calc_smap(vars);
	vars->background = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->minimap = mlx_new_image(vars->mlx, WIDTH -30, HEIGHT -30);
	vars->walls = mlx_new_image (vars->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(vars->mlx, vars->background, 0, 0);
	mlx_image_to_window(vars->mlx, vars->minimap, 30, 30);
	mlx_image_to_window(vars->mlx, vars->walls, 0, 0);
	vars->view_angle = 0.0; //should be depending on SWEN maybe exxtra func
	vars->background->instances->z = 1;
	vars->minimap->instances->z = 3;
	vars->walls->instances->z = 2;
	return (0);
}

	//ft_memset(vars.background->pixels, 255, WIDTH * HEIGHT * sizeof(int32_t));
		// vars.config.map_width = 5;
	// vars.config.map_height = 5;
	// vars.config.map = (char *[]){"11111", "10P01", "10101", "11001", "11111"};