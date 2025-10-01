/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:52:55 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/01 14:24:43 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

int	check_valid_path(char *path)
{
	char	*valid_path;

	valid_path = ft_strdup_no_newline(path);
	if (access(valid_path, R_OK) == 0)
	{
		free(path);
		free(valid_path);
		return (1);
	}
	printf("Invalid_path\n");
	free(path);
	free(valid_path);
	return (-1);
}

int	parse_texture(char *line, t_config *data)
{
	if (check_valid_path((ft_strdup(line + 3))) < 0)
		return (-1);
	if (starts_with(line, "NO") == 1 && data->no_set == 0)
	{
		data->texture_no = ft_strdup_no_newline(line + 3);
		data->no_set = 1;
	}
	else if (starts_with(line, "SO ") && !data->so_set)
	{
		data->texture_so = ft_strdup_no_newline(line + 3);
		data->so_set = 1;
	}
	else if (starts_with(line, "WE ") && !data->we_set)
	{
		data->texture_we = ft_strdup_no_newline(line + 3);
		data->we_set = 1;
	}
	else if (starts_with(line, "EA ") && !data->ea_set)
	{
		data->texture_ea = ft_strdup_no_newline(line + 3);
		data->ea_set = 1;
	}
	else
		return (-1);
	//this else handle the duplicate case
	return (0);
}

