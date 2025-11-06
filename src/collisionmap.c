/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisionmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:37:52 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/06 17:39:10 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_cmap(t_vars *vars, int x, int y, char ***cmap)
{
	if (vars->smap[x][y] == '0' &&
			(vars->smap[x -1][y] == '1' ||
			vars->smap[x + 1][y] == '1' ||
			vars->smap[x][y - 1] == '1' ||
			vars->smap[x][y + 1] == '1' ||
			vars->smap[x + 1][y + 1] == '1' ||
			vars->smap[x + 1][y - 1] == '1' ||
			vars->smap[x - 1][y + 1] == '1' ||
			vars->smap[x - 1][y - 1] == '1'))
		(*cmap)[x][y] = '1';
	else
		(*cmap)[x][y] = vars->smap[x][y];
}

char	**calc_cmap(t_vars *vars)
{
	char	**cmap;
	int		x;
	int		y;

	x = 0;
	y = 0;
	cmap = malloc(((vars->smap_width) + 1) * sizeof(char *));
	if (cmap == NULL)
		return (NULL);
	while (x < vars->smap_width)
	{
		cmap[x] = malloc((vars->smap_height + 1) * sizeof(char));
		if (cmap[x] == NULL)
			return (ft_free_array(cmap), NULL);
		while (y < vars->smap_height)
		{
			fill_cmap(vars, x, y, &cmap);
			y++;
		}
		cmap[x][y] = '\0';
		y = 0;
		x++;
	}
	cmap[x] = NULL;
	return (cmap);
}
