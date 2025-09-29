#include "cub3D.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
	//free;
	mlx_terminate(vars->mlx);
	exit(EXIT_SUCCESS);
	} 
}

int main()
{
	t_vars	vars;

	vars.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!vars.mlx)
	ft_putendl_fd("Error\n", 2);
	mlx_key_hook(vars.mlx, &ft_hook, &vars);
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	for (int i = 0; i < 300; i++){
		for (int j = 0; j <300; j++){
				mlx_put_pixel(vars.img, i, j, 0xFF0000);
		}
	}
	mlx_put_pixel(vars.img, 300, 300, 0x00FF00);
	mlx_loop(vars.mlx);

	//mlx_terminate(vars.mlx);
	printf("Hello World!\n");
	return (0);
}

