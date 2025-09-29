/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:29:28 by lusimon           #+#    #+#             */
/*   Updated: 2025/09/29 18:39:38 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

void	parser(int fd)
{
	char	*str;

	printf("%d\n", fd);
	printf("Hello World!\n");
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd);
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
