/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:58 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/16 14:40:08 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
				mlx_put_pixel(vars->minimap, x , y , 0x00FF0055);
			else
				mlx_put_pixel(vars->minimap, x , y , 0xFFFFFF55);
			y++;
		}
		y = 0;
		x++;
	}
	render_minimap_view(vars);
	return (0);
}

int	render_walls(t_vars *vars)
{
	int	x;
	int y;
	//int h;
	int	i;
	int j;
	t_hit_info hit_info;
	int	bottom_wall;
	int	top_wall;
	int	wall_height;
	int	jump;
	int	index;
	uint32_t color;
	mlx_texture_t *texture;

	i = 0;
	j = 0;
	x = 0;
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
	while (x < WIDTH)
	{
		hit_info = get_hit_info(vars, x);
		int adjust = 0;
		if (vars->config->player_dir == 'E')
			adjust = 0;
		else if (vars->config->player_dir == 'N')
			adjust += PI / 2;
		else if (vars->config->player_dir == 'W')
			adjust += PI;
		else if (vars->config->player_dir == 'S')
			adjust += 3 * PI / 2;
		hit_info.new_angle = normalise_angle(calculate_angle(vars, x) + adjust);
		if (facing_right(hit_info.new_angle) && facing_up(hit_info.new_angle))
		{
			if (hit_info.vertical_hit == 1)
				texture = vars->textures->east;
			else
				texture = vars->textures->north;
		}
		else if (facing_right(hit_info.new_angle) && facing_down(hit_info.new_angle))
		{
			if (hit_info.vertical_hit == 1)
				texture = vars->textures->east;
			else
				texture = vars->textures->south;
		}
		else if (facing_left(hit_info.new_angle) && facing_up(hit_info.new_angle))
		{
			if (hit_info.vertical_hit == 1)
				texture = vars->textures->west;
			else
				texture = vars->textures->north;
		}
		else if (facing_left(hit_info.new_angle) && facing_down(hit_info.new_angle))
		{
			if (hit_info.vertical_hit == 1)
				texture = vars->textures->west;
			else
				texture = vars->textures->south;
		}	
		bottom_wall = HEIGHT / 2 - hit_info.height / 2;
		top_wall = HEIGHT / 2 + hit_info.height / 2;
		wall_height = top_wall - bottom_wall;
		jump = texture->height / wall_height;
		//h = calculate_height(vars, x);
		y = HEIGHT / 2 - hit_info.height / 2;
		int ye = 0;
		while(y < HEIGHT / 2 + hit_info.height / 2)
		{
			// int tex_x = (int)(hit_info.percent_of_hit * texture->width);
			// int tex_y = (int)((y + (hit_info.height /2) - HEIGHT /2) * jump);
			// printf("y is %f\n", (y + (hit_info.height - HEIGHT /2));
			// index = (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;
			//index = ((((int)(y * texture->height / wall_height)) * (int)texture->width) + (int)(hit_info.percent_of_hit * (int)texture->width)) * (int)texture->bytes_per_pixel;
			//index = (((y * texture->height / wall_height) * texture->width) + hit_info.percent_of_hit * texture->width) * texture->bytes_per_pixel;
			// index = ((y + jump) * texture->width + (x + jump)) * texture->bytes_per_pixel;
			if ( x == 400)
			{
				printf("y value is %d, ye value is %d, wallheight is %d \n", y, ye, wall_height);
				printf("ye * jump is %d, ye * jump * texture->width is %d\n", (ye * jump), (ye * jump * texture->width));
				printf("value of x is %d\n", ((int)(hit_info.percent_of_hit * texture->width)));
			}
			int	texture_offset = (wall_height - (int)texture->height) / 2;
			int tex_y = (int)(ye * jump + texture_offset);
			// if (tex_y >= (int)texture->height)
   			// 	 tex_y = texture->height - 1;
			index = (tex_y * texture->width + ((int)(hit_info.percent_of_hit * texture->width))) * texture->bytes_per_pixel;
			if ( x == 400)
				printf("index value is %d\n", index);
			color = (texture->pixels[index + 0] << 24) | (texture->pixels[index + 2] << 16) | (texture->pixels[index + 1] << 8) | 0xFF;
			// use hit_info and vars->view_angle for right image
			// get single pixel like vars->images.east->pixels[1];
			// uint8_t pixel;
			// pixel = get_pixel(hit_info, vars);
			// mlx_put_pixel(vars->walls, x, y, pixel_to_int(pixel)); //maybe the unint8 value can be directly used for pixelcolor, maybe it needs tranfomration
			mlx_put_pixel(vars->walls, x, y, color);
			y++;
			ye++;
		}
		x++;
	}
	//printf("%hhu\n", vars->images.east->pixels[1]);
	//mlx_put_pixel(vars->walls, 300, 400, vars->images.west->pixels[1800]);
	printf("view_angle: %f\n", vars->view_angle);
	printf("color: %X\n", color);
	return (0);
}

int	render(t_vars *vars)
{
	render_background(vars);
	render_minimap(vars);
	render_walls(vars);
	return (0);
}