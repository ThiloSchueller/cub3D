/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:58 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/14 14:51:30 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_background(t_vars *vars)
{
	int	x;
	int	y;
	int	opac_ceiling;
	int	opac_floor;

	x = 0;
	y = 0;
	opac_ceiling = (vars->config->ceiling_color << 8) | 0xFF;
	opac_floor = (vars->config->floor_color << 8) | 0xFF;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(vars->background, x, y, opac_ceiling);
			else
				mlx_put_pixel(vars->background, x, y, opac_floor);
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
				mlx_put_pixel(vars->minimap, (int)(vars->scale.x * x),
					(int)(vars->scale.y * y), 0x00FF0055);
			else if (vars->smap[x][y] == '0')
				mlx_put_pixel(vars->minimap, (int)(vars->scale.x * x),
					(int)(vars->scale.y * y), 0xFFFFFF55);
			else
				mlx_put_pixel(vars->minimap, (int)(vars->scale.x * x),
					(int)(vars->scale.y * y), 0xFFFFFF00);
			y++;
		}
		y = 0;
		x++;
	}
	render_minimap_view(vars);
	return (0);
}

double	initialize_values(double *jump, t_vars *vars, int x)
{
	double	begin_texture;

	*jump = 0;
	begin_texture = 0;
	vars->hit_info = get_hit_info(vars, x);
	*jump = vars->hit_info.texture->height / (vars->hit_info.wall_height + 1);
	if (vars->hit_info.wall_height > 600)
	{
		begin_texture = (vars->hit_info.wall_height / 2
				- (double)HEIGHT / 2) * *jump;
		vars->hit_info.wall_height = 600;
	}
	return (begin_texture);
}

int	render_walls(t_vars *vars)
{
	int			x;
	int			y;
	int			ye;
	double		begin_texture;
	double		jump;

	x = 0;
	overwrite_previous_frame(vars);
	while (x < WIDTH)
	{
		begin_texture = initialize_values(&jump, vars, x);
		y = HEIGHT / 2 - vars->hit_info.wall_height / 2;
		ye = 0;
		while (y < HEIGHT / 2 + vars->hit_info.wall_height / 2)
		{
			mlx_put_pixel(vars->walls, x, y,
				get_color(vars, ye, jump, begin_texture));
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

// int	render_walls(t_vars *vars)
// {
// 	int			x;
// 	int			y;
// 	int			ye;
// 	t_hit_info	hit_info;
// 	double		jump;
// 	double		begin_texture;

// 	x = 0;
// 	overwrite_previous_frame(vars);
// 	while (x < WIDTH)
// 	{
// 		begin_texture = 0;
// 		hit_info = get_hit_info(vars, x);
// 		jump = hit_info.texture->height / (hit_info.wall_height + 1);
// 		//added this +1
// 		//we need this +1 for our jump to be a bit smaller
// 		//so that our tex_y (ye * jump)never goes above the texture->height 1024
// 		//failling case with wall_height = 230 ye = 231
// 		if (hit_info.wall_height > 600)
// 		{
// 			begin_texture = (hit_info.wall_height /2
				//- (double)HEIGHT /2) * jump;
// 			hit_info.wall_height = 600;
// 		}
// 		y = HEIGHT / 2 - hit_info.wall_height / 2;
// 		ye = 0;
// 		while(y < HEIGHT / 2 + hit_info.wall_height / 2)
// 		{
// 			mlx_put_pixel(vars->walls, x, y,
			//get_color(vars, ye, hit_info, jump, begin_texture));
// 			y++;
// 			ye++;
// 		}
// 		x++;
// 	}
// 	return (0);
// }