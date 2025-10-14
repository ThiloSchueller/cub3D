/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:58 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/14 12:46:19 by lusimon          ###   ########.fr       */
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
		if (vars->hit_info.vertical_hit == 1)
		{
			if (vars->view_angle > 0)
				texture = vars->textures->west;
			else
				texture = vars->textures->east;
		}
		else
		{
			if (vars->view_angle > 0)
				texture = vars->textures->north;
			else
				texture = vars->textures->south;
		}
		bottom_wall = HEIGHT / 2 - hit_info.height / 2;
		top_wall = HEIGHT / 2 + hit_info.height / 2;
		wall_height = top_wall - bottom_wall;
		jump = texture->height / wall_height;
		//h = calculate_height(vars, x);
		y = HEIGHT / 2 - hit_info.height / 2;
		while(y < HEIGHT / 2 + hit_info.height / 2)
		{
			index = ((y + jump) * texture->width + (x + jump)) * texture->bytes_per_pixel;
			color = (texture->pixels[index + 3] << 24) | (texture->pixels[index + 2] << 16) | (texture->pixels[index + 1] << 8) | texture->pixels[index + 0];
			// use hit_info and vars->view_angle for right image
			// get single pixel like vars->images.east->pixels[1];
			// uint8_t pixel;
			// pixel = get_pixel(hit_info, vars);
			// mlx_put_pixel(vars->walls, x, y, pixel_to_int(pixel)); //maybe the unint8 value can be directly used for pixelcolor, maybe it needs tranfomration
			mlx_put_pixel(vars->walls, x, y, color);
			y++;
		}
		x++;
	}
	//printf("%hhu\n", vars->images.east->pixels[1]);
	//mlx_put_pixel(vars->walls, 300, 400, vars->images.west->pixels[1800]);
	printf("view_angle: %f\n", vars->view_angle);
	return (0);
}

int	render(t_vars *vars)
{
	render_background(vars);
	render_minimap(vars);
	render_walls(vars);
	return (0);
}