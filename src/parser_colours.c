/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colours.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:54:16 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/06 15:22:24 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_validity_input(char *str)
{
	int	i;
	int	coma;
	int	digit;

	i = 0;
	coma = 0;
	digit = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ','
				|| str[i] == ' ' || str[i] == '	'))
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
			digit ++;
		if (str[i] == ',')
			coma ++;
		i++;
	}
	if (coma != 2 || digit > 9)
		return (-1);
	return (0);
}

int	color_to_hex(int red, int green, int blue)
{
	int	color;

	color = 0;
	color = red * 0x10000 + green * 0x100 + blue;
	return (color);
}

char	**array_color(char *str)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rgb = ft_split(str, ',');
	if (!rgb)
		return (NULL);
	while (rgb[i] != NULL)
		i++;
	if (i != 3)
	{
		while (rgb[j] != NULL)
		{
			free(rgb[j]);
			j++;
		}
		free(rgb);
		printf("Invalid colour input\n");
		return (NULL);
	}
	return (rgb);
}

int	color_str_to_int(char *str)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;
	int		color;

	rgb = array_color(str);
	if (rgb == NULL)
		return (-1);
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	if (red > 255 || green > 255 || blue > 255)
	{
		free_array(rgb);
		free(rgb);
		return (-1);
	}
	color = color_to_hex(red, green, blue);
	free_array(rgb);
	free(rgb);
	return (color);
}

int	parse_color(char *line, t_config *data)
{
	int		color;
	char	*str;

	str = ft_strdup_no_newline(&line[2]);
	if (check_validity_input(str) < 0 || color_str_to_int(str) < 0)
	{
		free(str);
		return (-1);
	}
	color = color_str_to_int(str);
	free(str);
	if (starts_with(line, "F ") == 1 && !data->floor_set)
	{
		data->floor_color = color;
		data->floor_set = 1;
	}
	else if (starts_with(line, "C ") == 1 && !data->ceil_set)
	{
		data->ceiling_color = color;
		data->ceil_set = 1;
	}
	else
		return (-1);
	return (0);
}
