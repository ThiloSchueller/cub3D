/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:21:42 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/08 13:32:00 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

// . The map must be enclosed by walls (1). No holes.
// . Spaces should only exist outside the playable map, not inside.
// . Map lines can have variable lengths (be careful to normalize).

//start from the player
//check if he is surrounded by walls and if he cannot fall in spaces

//also check that the map is surrounded by walls

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
	printf("valid_map\n");
	return (1);
}

int	check_outside_walls(char **map)
{
	int	i;
	int	j;
	int	inside_wall;

	i = -1;
	while (map[++i])
	{
		inside_wall = 0;
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (i == 0 || map[i + 1] == NULL)
			{
				if (!(map[i][j] == ' ' || map[i][j] == '1'))
					return (-1);
			}
			else if (map[i][j] == '1' && inside_wall == 0)
			{
				inside_wall = 1;
				if (j > 0 && map[i][j - 1] != ' ')
					return (-1);
			}
		}
	}
	return (1);
}

int	check_last_wall(char **map)
{
	int	i;
	int	j;
	int	end;
	int	last_wall;

	i = 0;
	end = 0;
	while (map[i][end] != '\0')
		end++;
	while (map[i])
	{
		last_wall = 0;
		j = (end -1);
		while (j >= 0)
		{
			if (map[i][j] == '1' && last_wall == 0 && i > 0)
			{
				last_wall = 1;
				if (j < (end -1) && map[i][j + 1] != ' ')
				{
					return (-1);
				}
			}
			j--;
		}
		i++;
	}
	return (1);
}

//I need to check that I have minimum one player position
int	player_position(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				player = 1;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (-1);
	return (1);
}

int	zero_touch_space(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!(i == 0 || map[i + 1] == NULL))
			{
				if (map[i][j] == '0' &&
					(map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
					return (-1);
				else if (map[i][j] == '0' &&
					(map[i + 1][j] == ' ' || map[i - 1][j] == ' '))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	player(char **map, t_config *data)
{
	if (data->x_position == -1 || data->y_position == -1)
		return (-1);
	if (data->x_position == 0 || data->x_position == data->map_width)
		return (-1);
	if (data->y_position == 0 || data->y_position == data->map_height)
		return (-1);
	if (map[data->y_position][data->x_position -1] == ' ')
		return (-1);
	if (map[data->y_position][data->x_position +1] == ' ')
		return (-1);
	if (map[data->y_position + 1][data->x_position] == ' ')
		return (-1);
	if (map[data->y_position - 1][data->x_position] == ' ')
		return (-1);
	return (1);
}

//still need to check the player area
//flood fill



