/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:58:19 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/04 17:00:31 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// bool	confirm_and_update_pos(t_fpoint pos, t_vars *vars)
// {
// 	if (vars->cmap[(int)pos.x][(int)pos.y] != '0')
// 		return;
// }

bool	confirm_move_x(double x_to_hit, double y_hit, double angle, t_vars *vars)
{
	if (x_to_hit < 0 || x_to_hit > vars->smap_width - 1 || y_hit < 0 || y_hit > vars->smap_height - 1)
		return (true);
	if (facing_right(angle) && (vars->cmap[(int)x_to_hit][(int)y_hit] == '1'))
		return (true);
	else if (facing_left(angle) && (vars->cmap[(int)x_to_hit -1][(int)(y_hit)] == '1'))
		return (true);
	return (false);
}

bool	confirm_move_y(double x_hit, double y_to_hit, double angle, t_vars *vars)
{
	if (y_to_hit < 0 || y_to_hit > vars->smap_height - 1 || x_hit < 0 || x_hit > vars->smap_width - 1)
		return (true);
	if (facing_down(angle) && (vars->cmap[(int)x_hit][(int)y_to_hit] == '1'))
		return (true);
	else if (facing_up(angle) && (vars->cmap[(int)x_hit][(int)y_to_hit -1] == '1'))
		return (true);
	return (false);
}

void	move_over_two_lines(t_vars *vars, double angle, t_fpoint new)
{
	t_fpoint step;
	t_fpoint next;

	next = lines_to_hit(vars->fpos, angle);
	step = calc_intersections(vars, angle, next.x, next.y);
	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
	{
		vars->fpos = step;
	}
	else if (step.x == next.x)
	{
		if (vars->cmap[(int)(step.x - 0.00001 * (2 * facing_right(angle) - 001))][(int)new.y] == '0')
			vars->fpos = (t_fpoint){step.x - 0.00001 * (2 * facing_right(angle) - 001), new.y};
		else
			vars->fpos = (t_fpoint){step.x - 0.00001 * (2 * facing_right(angle) - 001), next.y - 0.00001 * (2 * facing_down(angle) -001)};
		return ;
	}
	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
	{
		vars->fpos = step;
	}
	else if (step.y == next.y)
	{
		if (vars->cmap[(int)new.x][(int)(step.y - 0.00001 * (2 * facing_down(angle) -001))] == '0')
			vars->fpos = (t_fpoint){new.x, step.y - 0.00001 * (2 * facing_down(angle) -001)};
		else
			vars->fpos = (t_fpoint){next.x- 0.00001 * (2 * facing_right(angle) - 001), step.y - 0.00001 * (2 * facing_down(angle) -001)};
		return ;
	}
	next = lines_to_hit(vars->fpos, angle);
	step = calc_intersections(vars, angle, next.x, next.y);
	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
		vars->fpos = new;
	else if (step.x == next.x)
	{
		vars->fpos = (t_fpoint){step.x - 0.00001 * (2 * facing_right(angle) - 001), new.y};
	}
	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
		vars->fpos = new;
	else if (step.y == next.y)
		vars->fpos = (t_fpoint){new.x, step.y - 0.00001 * (2 * facing_down(angle) -001)};

}

void	move_over_one_line(t_vars *vars, double angle,t_fpoint new)
{
	t_fpoint next;
	t_fpoint step;
	next = lines_to_hit(vars->fpos, angle);

	step = calc_intersections(vars, angle, next.x, next.y);
	//printf("pos value x is = %f step value x is%f\n", vars->fpos.x, step.x);
	//printf("pos value y is = %f step value y is%f\n", vars->fpos.y, step.y);
	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
	{
		vars->fpos = new;
	}
	else if (step.x == next.x)
	{
		vars->fpos = (t_fpoint){next.x - 0.00001 * (2 * facing_right(angle) - 001), new.y};
	}
	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
	{
		vars->fpos = new;
	}
	else if (step.y == next.y)
	{
		vars->fpos = (t_fpoint){new.x, step.y - 0.00001 * (2 * facing_down(angle) -001)};
	}	
}

void	move_2d(t_vars *vars, t_fpoint d)
{
	double angle;
	t_fpoint new;

	new = vec_add(vars->fpos, d);
	angle = normalise_angle(atan2(-d.y, d.x));
	if ((int)vars->fpos.x == (int)new.x && (int)vars->fpos.y == (int)new.y)
	{
		vars->fpos = new;
	}
	else if ((int)vars->fpos.x != (int)new.x && (int)vars->fpos.y != (int)new.y)
	{
		move_over_two_lines(vars, angle, new);
	}
	else if ((int)vars->fpos.x != (int)new.x || (int)vars->fpos.y != (int)new.y)
	{
		move_over_one_line(vars, angle, new);
	}
	vars->pos.x = floor(vars->fpos.x);
 	vars->pos.y = floor(vars->fpos.y);
}


// void	move_over_two_lines(t_vars *vars, double angle, t_fpoint new)
// {
// 	t_fpoint step;
// 	t_fpoint next;

// 	next = lines_to_hit(vars->fpos, angle);
// 	step = calc_intersections(vars, angle, next.x, next.y);
// 	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
// 		vars->fpos = step;
// 	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
// 		vars->fpos = step;
// 	next = lines_to_hit(vars->fpos, angle);
// 	step = calc_intersections(vars, angle, next.x, next.y);
// 	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
// 		vars->fpos = new;
// 	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
// 		vars->fpos = new;
// }

// void	move_over_one_line(t_vars *vars, double angle,t_fpoint new)
// {
// 	t_fpoint next;
// 	t_fpoint step;
// 	next = lines_to_hit(vars->fpos, angle);

// 	step = calc_intersections(vars, angle, next.x, next.y);
// 	//printf("pos value x is = %f step value x is%f\n", vars->fpos.x, step.x);
// 	//printf("pos value y is = %f step value y is%f\n", vars->fpos.y, step.y);
// 	if (step.x == next.x && !confirm_move_x(step.x, step.y, angle, vars))
// 	{
// 		vars->fpos = new;
// 	}
// 	else if (step.x == next.x)
// 	{
// 		vars->fpos = (t_fpoint){next.x - 0.00001 * (2 * facing_right(angle) - 001), new.y};
// 		//vars->fpos = (t_fpoint){next.x - 0.00001, new.y};
// 	}
// 	else if (step.y == next.y && !confirm_move_y(step.x, step.y, angle, vars))
// 	{
// 		vars->fpos = new;
// 	}
// 	else if (step.y == next.y)
// 	{
// 		vars->fpos = (t_fpoint){new.x, step.y - 0.00001 * (2 * facing_down(angle) -001)};
// 		//vars->fpos = (t_fpoint){new.x, step.y - 0.00001};
// 	}	
// }

// void	move_2d(t_vars *vars, t_fpoint d)
// {
// 	double angle;
// 	t_fpoint new;

// 	new = vec_add(vars->fpos, d);
// 	angle = normalise_angle(atan2(-d.y, d.x));
// 	if ((int)vars->fpos.x == (int)new.x && (int)vars->fpos.y == (int)new.y)
// 	{
// 		vars->fpos = new;
// 	}
// 	else if ((int)vars->fpos.x != (int)new.x && (int)vars->fpos.y != (int)new.y)
// 	{
// 		printf("HERE\n");
// 		move_over_two_lines(vars, angle, new);
// 	}
// 	else if ((int)vars->fpos.x != (int)new.x || (int)vars->fpos.y != (int)new.y)
// 	{
// 		move_over_one_line(vars, angle, new);
// 	}
// 	vars->pos.x = floor(vars->fpos.x);
//  	vars->pos.y = floor(vars->fpos.y);
// }
