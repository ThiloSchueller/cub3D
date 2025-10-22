/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:18:10 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/22 17:22:06 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3D.h"

void	overwrite_previous_frame(t_vars *vars)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < WIDTH) //overwriting the previous frame
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



mlx_texture_t *define_texture(t_vars *vars, int x, float angle, bool vertical_hit)
{
	(void)x;
		//angle = normalise_angle(calculate_angle(vars, x));
		if (facing_right(angle) && facing_up(angle))
		{
			if (vertical_hit == 1)
				return(vars->textures->east);
			else
				return(vars->textures->north);
		}
		else if (facing_right(angle) && facing_down(angle))
		{
			if (vertical_hit == 1)
				return(vars->textures->east);
			else
				return(vars->textures->south);
		}
		else if (facing_left(angle) && facing_up(angle))
		{
			if (vertical_hit == 1)
				return(vars->textures->west);
			else
				return(vars->textures->north);
		}
		else if (facing_left(angle) && facing_down(angle))
		{
			if (vertical_hit == 1)
				return(vars->textures->west);
			else
				return(vars->textures->south);
		}
		return (NULL);
}

uint32_t	get_color(t_vars *vars, int ye ,t_hit_info hit_info, float jump, float begin_texture)
{
	int	index;
	uint32_t color;
	int tex_y;

	(void)vars;
	tex_y = (int)((ye * jump) + begin_texture);
	// if (tex_y >= ((int)(hit_info.texture->height - begin_texture)))
	// 	 tex_y = (hit_info.texture->height - begin_texture) - 1; // why is this necessary ? bad bounds before maybe
	// not needed anymore
	index = (tex_y * hit_info.texture->width + ((int)(hit_info.percent_of_hit * hit_info.texture->width))) * hit_info.texture->bytes_per_pixel;

	color = (hit_info.texture->pixels[index + 0] << 24) | (hit_info.texture->pixels[index + 2] << 8) | (hit_info.texture->pixels[index + 1] << 16) | 0xFF;
	return (color);
}