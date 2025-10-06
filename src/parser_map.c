/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:16:27 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/06 13:11:42 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] != ' ' && line[i] != '1')
		return (0);
	else
		return (1);
}

void	parse_map(char *line, t_config *data)
{
	int	len;

	len = ft_strlen(line);
	if (len > data->map_width)
		data->map_width = len;
	data->map_height++;
	free(line);
}

void	free_row(char **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
}

void	create_empty_map(t_config *data)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = malloc(sizeof(char *) * data->map_height);
	// I removed the map_height + 1
	if (!map)
		return ;
	while (i < data->map_height)
	{
		map[i] = malloc(sizeof(char) * (data->map_width + 1));
		if (!map[i])
		{
			free_row(map, i);
			return ;
		}
		j = 0;
		while (j < data->map_width)
		{
			map[i][j] = '0';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	//map[i] = NULL;
	data->map = map;
}

void	print_map(t_config *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->map == NULL)
		return ;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			printf("%c", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


//map_start = 0
//the line count of map start is one
//map_end is line_count -1

//[0]
//[1]
//[2]
//line_count = 3
