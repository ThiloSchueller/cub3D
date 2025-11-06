/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:18:10 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/06 15:35:49 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	overwrite_previous_frame(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			mlx_put_pixel(vars->walls, i, j, 0x00000000);
			j++;
		}
		j = 0;
		i++;
	}
}

mlx_texture_t	*right_texture(t_vars *vars, double angle, bool vertical_hit)
{
	if (facing_up(angle))
	{
		if (vertical_hit == 1)
			return (vars->textures->east);
		else
			return (vars->textures->north);
	}
	else if (facing_right(angle) && facing_down(angle))
	{
		if (vertical_hit == 1)
			return (vars->textures->east);
		else
			return (vars->textures->south);
	}
	else
		return (NULL);
}

mlx_texture_t	*left_texture(t_vars *vars, double angle, bool vertical_hit)
{
	if (facing_up(angle))
	{
		if (vertical_hit == 1)
			return (vars->textures->west);
		else
			return (vars->textures->north);
	}
	else if (facing_down(angle))
	{
		if (vertical_hit == 1)
			return (vars->textures->west);
		else
			return (vars->textures->south);
	}
	return (NULL);
}

mlx_texture_t	*define_texture(t_vars *vars, double angle, bool vertical_hit)
{
	if (facing_right(angle))
		return (right_texture(vars, angle, vertical_hit));
	else if (facing_left(angle))
		return (left_texture(vars, angle, vertical_hit));
	return (NULL);
}

uint32_t	get_color(t_vars *vars, int ye, double jump, double begin_texture)
{
	int			index;
	uint32_t	color;
	int			tex_y;

	(void)vars;
	tex_y = (int)((ye * jump) + begin_texture);
	index = (tex_y * vars->hit_info.texture->width
			+ ((int)(vars->hit_info.percent_of_hit
					* vars->hit_info.texture->width)))
		* vars->hit_info.texture->bytes_per_pixel;
	color = (vars->hit_info.texture->pixels[index + 0] << 24)
		| (vars->hit_info.texture->pixels[index + 2] << 8)
		| (vars->hit_info.texture->pixels[index + 1] << 16) | 0xFF;
	return (color);
}

	// if (tex_y >= ((int)(hit_info.texture->height - begin_texture)))
	// 	 tex_y = (hit_info.texture->height - begin_texture) - 1;
	// why is this necessary ? bad bounds before maybe
	// not needed anymore