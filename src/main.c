#include "cub3D.h"

int main()
{
	t_vars	vars;

	vars.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!vars.mlx)
	ft_putendl_fd("Error\n", 2);
	mlx_key_hook(vars.mlx, &ft_hook, &vars);
	vars.background = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	ft_memset(vars.background->pixels, 255, WIDTH * HEIGHT * sizeof(int32_t));
	mlx_image_to_window(vars.mlx, vars.background, 0, 0);
	vars.background->instances->z = 1;
	render_background(&vars);
	vars.minimap = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(vars.mlx, vars.minimap, 30, 30);
	vars.minimap->instances->z = 2;

	render_minimap(&vars);
	mlx_loop(vars.mlx);

	//mlx_terminate(vars.mlx);
	printf("Hello World!\n");
	return (0);
}

