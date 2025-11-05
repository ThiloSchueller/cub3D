/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:34:37 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/05 12:52:19 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	copy_line(char *dst, char *src, t_config *data)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		if (!(src[i] == ' ' || src[i] == '1' || src[i] == '0'
				|| src[i] == 'N' || src[i] == 'S'
				|| src[i] == 'W' || src[i] == 'E'))
			return (-1);
		if (src[i] == 'N' || src[i] == 'S' || src[i] == 'W' || src[i] == 'E')
		{
			if (ft_strlen(&data->player_dir) > 0)
				return (-1);
			data->player_dir = src[i];
			data->x_position = i;
		}
		(void)data;
		dst[i] = src[i];
		i++;
	}
	return (1);
}

int	compare_update_map(char *line, t_config *data)
{
	static int	i = 0;

	if (copy_line(data->map[i], line, data) < 0)
		return (-1);
	if (data->x_position != -1 && data->y_position == -1)
		data->y_position = i;
	i++;
	return (1);
}

void	parser_map_2nd_round(t_config *data, char *file)
{
	int		fd;
	char	*str;
	char	*line;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL && data->stop == 0)
	{
		if (str[0] != '\n' && is_map_line(str))
		{
			line = ft_strdup_no_newline_map(str);
			if (compare_update_map(line, data) < 0)
			{
				data->stop = 1;
				free(line);
				free(str);
				close(fd);
				return ;
			}
			free(line);
		}
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
}

void	parser(int fd, t_config *data, char *file)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL && data->stop == 0)
	{
		if (str[0] != '\n')
		{
			if (is_map_line(str) && parse_texture_color_before(data))
				parse_map(ft_strdup_no_newline_map(str), data);
			else
				parse_element(str, data);
		}
		if (str)
			free(str);
		if (data->stop == 0)
			str = get_next_line(fd);
	}
	close (fd);
	if (data->map_before == 1)
		data->stop = 1;
	if (data->stop == 0)
	{
		create_empty_map(data);
		parser_map_2nd_round(data, file);
	}
	check_map(data);
	if (data->stop == 0)
	{
		// printf("NO: %s\n", data->texture_no);
		// printf("SO: %s\n", data->texture_so);
		// printf("WE: %s\n", data->texture_we);
		// printf("EA: %s\n", data->texture_ea);
		// printf("\n");
		// printf("floor color: %x\n", data->floor_color);
		// printf("ceiling color: %x\n", data->ceiling_color);
		// printf("\n");
		printf("map_width: %d\n", data->map_width);
		printf("map_height: %d\n", data->map_height);
		// printf("\n");
		// printf("x_position: %i\n", data->x_position);
		// printf("y_position: %i\n", data->y_position);
		// printf("direction: %c\n", data->player_dir);
		print_map(data);
	}
}

void	parse_element(char *line, t_config *data)
{
	int		check;
	char	*new_line;

	check = 0;
	new_line = remove_space_tab_between(line);
	if (starts_with(new_line, "NO ") == 1 || starts_with(new_line, "SO ") == 1
		|| starts_with(new_line, "WE ") == 1 || starts_with(new_line, "EA ") == 1)
		check = parse_texture(new_line, data);
	else if (starts_with(new_line, "F ") == 1 || starts_with(new_line, "C ") == 1)
		check = parse_color(new_line, data);
	free(new_line);
	if (check < 0)
	{
		data->stop = 1;
		return ;
	}
}
