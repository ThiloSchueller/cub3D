/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_steep_angles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:59:00 by tschulle          #+#    #+#             */
/*   Updated: 2025/10/23 15:17:53 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_hit_info	hit_top(t_vars *vars, float angle)
{
	t_hit_info	hit_info;
	t_fpoint	ray_pos;

	ray_pos = vars->fpos;
	ray_pos.y = floor(ray_pos.y);
	while (1)
	{
		if (confirm_hit_y(ray_pos.x, ray_pos.y, angle, vars))
			break;
		else
			ray_pos.y -= 1;
	}
	hit_info.distance = distance_two_points(ray_pos, vars->fpos);
	// hit_info.distance = distance_two_points(ray_pos, vars->fpos) * cos(angle - vars->view_angle);
	hit_info.percent_of_hit = fmod(ray_pos.x, SCALE) / SCALE;
	hit_info.vertical_hit = false;
	return (hit_info);
}

t_hit_info	hit_right(t_vars *vars, float angle)
{
	t_hit_info	hit_info;
	t_fpoint	ray_pos;

	ray_pos = vars->fpos;
	ray_pos.x = ceil(ray_pos.x);
	while (1)
	{
		if (confirm_hit_x(ray_pos.x, ray_pos.y, angle, vars))
			break;
		else
			ray_pos.x += 1;
	}
	hit_info.distance = distance_two_points(ray_pos, vars->fpos);
	//hit_info.distance = distance_two_points(ray_pos, vars->fpos) * cos(angle - vars->view_angle);
	hit_info.percent_of_hit = fmod(ray_pos.y, SCALE) / SCALE;
	hit_info.vertical_hit = true;
	return (hit_info);
}
t_hit_info	hit_left(t_vars *vars, float angle)
{
	t_hit_info	hit_info;
	t_fpoint	ray_pos;

	ray_pos = vars->fpos;
	ray_pos.x = floor(ray_pos.x);
	while (1)
	{
		if (confirm_hit_x(ray_pos.x, ray_pos.y, angle, vars))
			break;
		else
			ray_pos.x -= 1;
	}
	hit_info.distance = distance_two_points(ray_pos, vars->fpos);
	//hit_info.distance = distance_two_points(ray_pos, vars->fpos) * cos(angle - vars->view_angle);
	hit_info.percent_of_hit = fmod(ray_pos.y, SCALE) / SCALE;
	hit_info.vertical_hit = true;
	return (hit_info);
}

t_hit_info	hit_bot(t_vars *vars, float angle)
{
	t_hit_info	hit_info;
	t_fpoint	ray_pos;

	ray_pos = vars->fpos;
	ray_pos.y = ceil(ray_pos.y);
	while (1)
	{
		if (confirm_hit_y(ray_pos.x, ray_pos.y, angle, vars))
			break;
		else
			ray_pos.y += 1;
	}
	hit_info.distance = distance_two_points(ray_pos, vars->fpos);
	//hit_info.distance = distance_two_points(ray_pos, vars->fpos) * cos(angle - vars->view_angle);
	hit_info.percent_of_hit = fmod(ray_pos.x, SCALE) / SCALE;
	hit_info.vertical_hit = false;
	return (hit_info);
}
