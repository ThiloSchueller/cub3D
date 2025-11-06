/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/06 17:36:10 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_fpoint	w_key(t_vars *vars)
{
	t_fpoint	re;

	re.x = cos(vars->view_angle);
	re.y = -sin(vars->view_angle);
	return (re);
}

t_fpoint	s_key(t_vars *vars)
{
	t_fpoint	re;

	re.x = -cos(vars->view_angle);
	re.y = sin(vars->view_angle);
	return (re);
}

t_fpoint	d_key(t_vars *vars)
{
	t_fpoint	re;

	re.x = sin(vars->view_angle);
	re.y = cos(vars->view_angle);
	return (re);
}

t_fpoint	a_key(t_vars *vars)
{
	t_fpoint	re;

	re.x = -sin(vars->view_angle);
	re.y = -cos(vars->view_angle);
	return (re);
}

// bool	west_closer(t_vars *vars, double dx)
// {
// 	(void)dx;
// 	double	distance_west;
// 	double	distance_east;
// 	distance_east = hit_right(vars, 0).distance;
// 	distance_west = hit_left(vars, PI).distance;
// 	//if (vars->fpos.x + dx < 30)
// 	if (distance_west < distance_east)
// 		return (true);
// 	else
// 		return (false);
// }
// bool	south_closer(t_vars* vars, double dy)
// {
// 	(void)dy;
// 	double	distance_south;
// 	double	distance_north;
// 	//if (vars->fpos.y + dy > 30)
// 	distance_south = hit_bot(vars, PI * 3 / 2).distance;
// 	distance_north = hit_top(vars, 0.5 * PI).distance;
// 	if (distance_south < distance_north)
// 	{
// 		// printf("distance south is %f\n", distance_south);
// 		// printf("distance north is %f\n", distance_north);
// 		// printf("south closer\n");
// 		// fflush(stdout);
// 		return (true);
// 	}
// 	else
// 	{
// 		// printf("distance south is %f\n", distance_south);
// 		// printf("distance north is %f\n", distance_north);
// 		// printf("north closer\n");
// 		// fflush(stdout);
// 		return (false);
// 	}
// }
