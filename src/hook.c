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