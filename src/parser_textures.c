/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:52:55 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/25 11:57:04 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (starts_with(line, "SO") == 1 && data->so_set == 0)
	{
		data->texture_so = ft_strdup_no_newline(line + 3);
		data->so_set = 1;
	}
	else if (starts_with(line, "WE") == 1 && data->we_set == 0)
	{
		data->texture_we = ft_strdup_no_newline(line + 3);
		data->we_set = 1;
	}
	else if (starts_with(line, "EA") == 1 && data->ea_set == 0)
	{
		data->texture_ea = ft_strdup_no_newline(line + 3);
		data->ea_set = 1;
	}
	else
		return (-1);
	return (0);
}

// int	ft_strncmp_back(const char *s1, const char *s2, size_t n)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (-1);
// 	while (s1[i] != '\0')
// 		i++;
// 	while (s2[j] != '\0')
// 		j++;
// 	while (n > 0)
// 	{
// 		if (s1[i] != s2[j])
// 			return (-1);
// 		i--;
// 		j--;
// 		n--;
// 	}
// 	return (1);
// }

// if (ft_strncmp_back(valid_path, ".png", 3) == 1
// 	&& access(valid_path, R_OK) == 0)