/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:58:19 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/06 17:18:27 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	second_step(t_vars *vars, double angle, t_fpoint new)
{
	t_fpoint	step;
	t_fpoint	next;

	next = lines_to_hit(vars->fpos, angle);
	step = calc_intersections(vars, angle, next.x, next.y);
	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
		vars->fpos = new;
	else if (step.x == next.x)
		vars->fpos = (t_fpoint){step.x + ox(angle), new.y};
	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
		vars->fpos = new;
	else if (step.y == next.y)
		vars->fpos = (t_fpoint){new.x, step.y + oy(angle)};
}

void	move_over_two_lines(t_vars *vars, double angle, t_fpoint new)
{
	t_fpoint	step;
	t_fpoint	next;

	next = lines_to_hit(vars->fpos, angle);
	step = calc_intersections(vars, angle, next.x, next.y);
	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
		vars->fpos = step;
	else if (step.x == next.x)
	{
		if (vars->cmap[(int)(step.x + ox(angle))][(int)new.y] == '0')
			vars->fpos = (t_fpoint){step.x + ox(angle), new.y};
		else
			vars->fpos = (t_fpoint){step.x + ox(angle), next.y + oy(angle)};
	}
	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
		vars->fpos = step;
	else if (step.y == next.y)
	{
		if (vars->cmap[(int)new.x][(int)(step.y + oy(angle))] == '0')
			vars->fpos = (t_fpoint){new.x, step.y + oy(angle)};
		else
			vars->fpos = (t_fpoint){next.x + ox(angle), step.y + oy(angle)};
	}
	if (vars->fpos.x == step.x && vars->fpos.y == step.y)
		second_step(vars, angle, new);
}

void	move_over_one_line(t_vars *vars, double angle, t_fpoint new)
{
	t_fpoint	next;
	t_fpoint	step;

	next = lines_to_hit(vars->fpos, angle);
	step = calc_intersections(vars, angle, next.x, next.y);
	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
		vars->fpos = new;
	else if (step.x == next.x)
		vars->fpos = (t_fpoint){next.x + ox(angle), new.y};
	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
		vars->fpos = new;
	else if (step.y == next.y)
		vars->fpos = (t_fpoint){new.x, step.y + oy(angle)};
}

void	move_2d(t_vars *vars, t_fpoint d)
{
	double		angle;
	t_fpoint	new;

	new = vec_add(vars->fpos, d);
	angle = normalise_angle(atan2(-d.y, d.x));
	if ((int)vars->fpos.x == (int)new.x && (int)vars->fpos.y == (int)new.y)
		vars->fpos = new;
	else if ((int)vars->fpos.x != (int)new.x && (int)vars->fpos.y != (int)new.y)
		move_over_two_lines(vars, angle, new);
	else if ((int)vars->fpos.x != (int)new.x || (int)vars->fpos.y != (int)new.y)
		move_over_one_line(vars, angle, new);
	vars->pos.x = floor(vars->fpos.x);
	vars->pos.y = floor(vars->fpos.y);
}
