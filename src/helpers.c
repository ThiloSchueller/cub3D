/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:50:44 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/17 13:55:39 by tschulle         ###   ########.fr       */
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
