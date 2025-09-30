/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:14:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/09/30 15:57:45 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if (!data)
        return;

    // Flags
    data->no_set = 0;
    data->so_set = 0;
    data->we_set = 0;
    data->ea_set = 0;
    data->floor_set = 0;
    data->ceil_set = 0;
    data->map_set = 0;

    // Texture paths
    data->texture_no = NULL;
    data->texture_so = NULL;
    data->texture_we = NULL;
    data->texture_ea = NULL;

    // Colors
    data->floor_color = -1;
    data->ceiling_color = -1;

    // Map
    data->map = NULL;
    data->map_width = 0;
    data->map_height = 0;

    // Player
    data->player_x = -1;
    data->player_y = -1;
    data->player_dir = '\0';
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_config	*data;

	fd = 0;
	data = NULL;
	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	fd = check_file(argv[1]);
	if (fd > 2)
	{
		init_data(data);
		parser(fd, data);
	}
	return (0);
}


