/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:50:44 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/06 15:28:23 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_player_char(char c)
{
	if ((c == 'E') || (c == 'N') || (c == 'W') || (c == 'S'))
		return (true);
	return (false);
}

void	ft_free_array(char **a)
{
	int	i;

	i = 0;
	if (a == NULL)
		return ;
	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
}

int	parse_texture_color_before(t_config *data)
{
	if (data->no_set == 1 && data->so_set == 1 && data->we_set == 1
		&& data->ea_set == 1 && data->floor_set == 1 && data->ceil_set == 1)
		return (1);
	data->map_before = 1;
	return (1);
}

void	check_map_before(t_config *data)
{
	if (data->map_before == 1)
		data->stop = 1;
}
