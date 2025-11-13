/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:21:42 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/13 16:20:15 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

char	**map_copy(t_config *data)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!map)
		return (NULL);
	while (i < data->map_height)
	{
		map[i] = malloc(sizeof(char) * (data->map_width + 1));
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
		j = 0;
		while (j < data->map_width)
			map[i][j++] = ' ';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	print_copy(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	check_map(t_config *data)
{
	char	**map;
	int		i;
	int		j;

	if (data->stop == 1)
		return ;
	i = 0;
	map = map_copy(data);
	while (map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			map[i][j] = data->map[i][j];
			j++;
		}
		i++;
	}
	if (check_conditions_map(map, data) < 0)
		data->stop = 1;
	free_map(map);
}

int	check_conditions_map(char **map, t_config *data)
{
	if (check_outside_walls(map) < 1)
		return (-1);
	if (check_last_wall(map) < 1)
		return (-1);
	if (player_position(map) < 1)
		return (-1);
	if (zero_touch_space(map) < 1)
		return (-1);
	if (player(map, data) < 1)
		return (-1);
	return (1);
}

void	start_map(t_config *data, char *file)
{
	create_empty_map(data);
	parser_map_2nd_round(data, file);
}
