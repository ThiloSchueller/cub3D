/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:21:42 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/07 13:52:19 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

// . The map must be enclosed by walls (1). No holes.
// . Spaces should only exist outside the playable map, not inside.
// . Map lines can have variable lengths (be careful to normalize).

//start from the player
//check if he is surrounded by walls and if he cannot fall in spaces

//also check that the map is surrounded by walls
