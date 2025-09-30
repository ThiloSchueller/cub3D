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
				mlx_put_pixel(vars->background, x, y, 0xFFFFFF);
			else
				mlx_put_pixel(vars->background, x, y, 177000);
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

	x = 0;
	while (x < 50)
	{
		mlx_put_pixel(vars->minimap, x , 0 , 0x00000055);
		x++;
	}
	return (0);
}