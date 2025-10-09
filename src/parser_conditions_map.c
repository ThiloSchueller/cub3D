/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_conditions_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:52:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/09 12:52:37 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

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
	end = ft_strlen(map[i]);
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
					return (-1);
			}
			j--;
		}
		i++;
	}
	return (1);
}

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
