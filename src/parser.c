/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:29:28 by lusimon           #+#    #+#             */
/*   Updated: 2025/09/30 18:12:51 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

int	starts_with(char *line, char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (ft_strncmp(line, str, str_len) != 0)
		return (-1);
	return (1);
}

void	parser(int fd, t_config *data)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		parse_element(str, data);
		free(str);
		str = get_next_line(fd);
	}
}

char	*ft_strdup_n(const char *s1)
{
	char	*p;

	p = (char *) malloc((ft_strlen(s1)) * sizeof(char));
	if (p == NULL)
		return (0);
	ft_memcpy(p, s1, ft_strlen(s1) - 1);
	p[ft_strlen(s1)] = '\0';
	return (p);
}

//we need this helper_function to not include the \n
//when we look at the validity of the path

int	check_valid_path(char *path)
{
	char	*valid_path;

	valid_path = ft_strdup_n(path);
	if (access(valid_path, R_OK) == 0)
		return (1);
	printf("Invalid_path\n");
	return (-1);
}

int	parse_texture(char *line, t_config *data)
{
	char *path;

	path = ft_strdup(line + 3);
	if (check_valid_path(path) < 0)
		return (-1);
	if (starts_with(line, "NO") == 1 && data->no_set == 0)
	{
		data->texture_no = ft_strdup(line + 3);
		data->no_set = 1;
	}
	else if (starts_with(line, "SO ") && !data->so_set)
	{
		data->texture_so = ft_strdup(&line[4]);
		data->so_set = 1;
	}
	else if (starts_with(line, "WE ") && !data->we_set)
	{
		data->texture_we = ft_strdup(&line[4]);
		data->we_set = 1;
	}
	else if (starts_with(line, "EA ") && !data->ea_set)
	{
		data->texture_ea = ft_strdup(&line[4]);
		data->ea_set = 1;
	}
	return (0);
}

int	check_validity_input(char *str)
{
	int	i;
	int	coma;

	i = 0;
	coma = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ','))
			return (-1);
		if (str[i] == ',')
			coma ++;
		i++;
	}
	if (coma != 2 || i > 11)
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

int	color_str_to_int(char *str)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;
	int		color;

	rgb = ft_split(str, ',');
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	if (red > 255 || green > 255 || blue > 255)
		return (-1);
	color = color_to_hex(red, green, blue);
	return (color);
}

int	parse_color(char *line, t_config *data)
{
	int	color;

	if (check_validity_input(&line[2]) < 0)
		return (-1);
	color = color_str_to_int(&line[2]);
	if (color < 0)
		return (-1);
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

void	parse_element(char *line, t_config *data)
{
	int	check;

	check = 0;
	if (starts_with(line, "NO ") == 1 || starts_with(line, "SO ") == 1
		|| starts_with(line, "WE ") == 1 || starts_with(line, "EA ") == 1)
	{
		printf("check_texture\n");
		check = parse_texture(line, data);
	}
	else if (starts_with(line, "F ") == 1 || starts_with(line, "C ") == 1)
	{
		printf("check_color\n");
		check = parse_color(line, data);
	}
	if (check < 0)
		printf("Invalid data, need to free\n");
	printf("parse successfull\n");
}

//All required elements are present**.
//No duplicates** of identifiers (e.g. two `NO` lines).
//All values are valid** (colors in range, paths exist, etc.).

// **You Need:**

//    * ✅ 4 wall textures: `NO`, `SO`, `WE`, `EA`
//    * ✅ 1 floor color (`F R,G,B`) — values must be in [0, 255]
//    * ✅ 1 ceiling color (`C R,G,B`) — same
//    * ✅ A valid **map**, which:

//      * Contains only allowed characters: `0`, `1`, `N`, `S`, `E`, `W`, and spaces
//      * Has **exactly one** player start position
//      * Is **properly enclosed** (walls all around)
//    * ✅ You plan to **store the extracted data** in a struct (correct!)
//    * ✅ You consider parsing **done once all is stored** (almost — with a note below 👇)


// ✅ So the parser + GNL combo works like this:

// GNL → gives you one line at a time

// Parser → decides what that line means and stores it in the right place


//check the validity of maps
// when we have unregular maps
// we still need to store those maps as rectengular map
// we will just store spaces instead

//Since some rows are shorter than the maximum width, you usually pad them with spaces when storing in your 2D array.

// char **map; // map[height][width]

// for each row {
//     copy characters
//     pad the rest with ' ' or '1' (depending on your approach)
// }
