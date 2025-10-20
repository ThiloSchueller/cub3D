/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:58 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/20 13:54:30 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_background(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x < WIDTH)
	{
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(vars->background, x, y, vars->config->ceiling_color);
			else
				mlx_put_pixel(vars->background, x, y, vars->config->floor_color); //ADD OPACITY? so 0xffffffff, istead of 0xffffff
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int	render_minimap(t_vars *vars)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (x < vars->smap_width)
	{
		while (y < vars->smap_height)
		{
			if (vars->smap[x][y] == '1')
				mlx_put_pixel(vars->minimap, (int)(vars->scale.x * x), (int)(vars->scale.y * y), 0x00FF0055);
			else if (vars->smap[x][y] == '0')
				mlx_put_pixel(vars->minimap, (int)(vars->scale.x * x), (int)(vars->scale.y * y), 0xFFFFFF55);
			else
				mlx_put_pixel(vars->minimap, (int)(vars->scale.x * x), (int)(vars->scale.y * y), 0xFFFFFF00);
			y++;
		}
		y = 0;
		x++;
	}
	render_minimap_view(vars);
	return (0);
}



// int	get_color(vars, x, y, ye)
// {
// 	mlx_texture_t *texture;
// 	t_hit_info hit_info;
// 	int	wall_height;
// 	int	jump;
// 	int	index;

// 	texture = define_texture(vars, x);
// 	hit_info = get_hit_info(vars, x);
// 	wall_height = (HEIGHT / 2 + hit_info.height / 2) - (HEIGHT / 2 - hit_info.height / 2);
// 	jump = texture->height / wall_height;

// 	if ( x == 400)
// 	{
// 		printf("y value is %d, ye value is %d, wallheight is %d \n", y, ye, wall_height);
// 		printf("ye * jump is %d, ye * jump * texture->width is %d\n", (ye * jump), (ye * jump * texture->width));
// 		printf("value of x is %d\n", ((int)(hit_info.percent_of_hit * texture->width)));
// 	}
// 	//int	texture_offset = (wall_height - (int)texture->height) / 2;
// 	int tex_y = (int)(ye * jump);// + jump /2; //+ texture_offset);
// 	if (tex_y >= (int)texture->height)
// 		 tex_y = texture->height - 1;
// 	index = (tex_y * texture->width + ((int)(hit_info.percent_of_hit * texture->width))) * texture->bytes_per_pixel;
// 	if ( x == 400)
// 		printf("index value is %d\n", index);
// 	return((texture->pixels[index + 0] << 24) | (texture->pixels[index + 2] << 16) | (texture->pixels[index + 1] << 8) | 0xFF);
	
	
// }



int	render_walls(t_vars *vars)
{
	int	x;
	int y;
	int ye;
	t_hit_info hit_info;
	float	jump;


	x = 0;
	overwrite_previous_frame(vars);
	while (x < WIDTH)
	{
		hit_info = get_hit_info(vars, x);
		jump = hit_info.texture->height / hit_info.wall_height;
		y = HEIGHT / 2 - hit_info.wall_height / 2;
		ye = 0;
		while(y < HEIGHT / 2 + hit_info.wall_height / 2)
		{
			//int	texture_offset = (wall_height - (int)texture->height) / 2;
			mlx_put_pixel(vars->walls, x, y, get_color(vars, ye, hit_info, jump));
			y++;
			ye++;
		}
		x++;
	}
	return (0);
}

int	render(t_vars *vars)
{
	render_background(vars);
	if (vars->mmswitch == true)
		render_minimap(vars);
	render_walls(vars);
	return (0);
}

			// if ( x == 400)
			// 	printf("index value is %d\n", index);
						// if ( x == 400)
			// {
			// 	printf("y value is %d, ye value is %d, wallheight is %d \n", y, ye, wall_height);
			// 	printf("ye * jump is %d, ye * jump * texture->width is %d\n", (ye * jump), (ye * jump * texture->width));
			// 	printf("value of x is %d\n", ((int)(hit_info.percent_of_hit * texture->width)));
			// }
					//wall_height = (HEIGHT / 2 + hit_info.height / 2) - (HEIGHT / 2 - hit_info.height / 2);