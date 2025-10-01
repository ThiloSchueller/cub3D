/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:29:28 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/01 14:32:42 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

void	parser(int fd, t_config *data)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL && data->stop == 0)
	{
		if (str[0] != '\n')
			parse_element(str, data);
		free(str);
		str = get_next_line(fd);
	}
	if (data->stop == 0)
	{
		printf("parse successfull\n");
		printf("\n");
		printf("NO: %s\n", data->texture_no);
		printf("SO: %s\n", data->texture_so);
		printf("WE: %s\n", data->texture_we);
		printf("EA: %s\n", data->texture_ea);
		printf("floor color: %x\n", data->floor_color);
		printf("ceiling color: %x\n", data->ceiling_color);
	}
}

void	parse_element(char *line, t_config *data)
{
	int	check;

	check = 0;
	if (starts_with(line, "NO ") == 1 || starts_with(line, "SO ") == 1
		|| starts_with(line, "WE ") == 1 || starts_with(line, "EA ") == 1)
		check = parse_texture(line, data);
	else if (starts_with(line, "F ") == 1 || starts_with(line, "C ") == 1)
		check = parse_color(line, data);
	if (check < 0)
	{
		data->stop = 1;
		printf("Ivalid input\n");
		//I need to free what I already allocated in my struct
		return ;
	}
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
