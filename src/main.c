/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:14:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/22 15:46:34 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

int	main(int argc, char *argv[])
{
	int			fd;
	t_config	*data;

	fd = 0;
	data = check_arg_map(argc, argv);
	if (!data)
		return (1);
	t_vars	vars;
	vars.textures = malloc(sizeof(t_texture));
	vars.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!vars.mlx)
		ft_exit(ERROR_MLX, &vars);
	vars.config = data;
	ft_get_textures(&vars);
	mlx_key_hook(vars.mlx, &ft_key_hook, &vars);
	mlx_loop_hook(vars.mlx, &ft_loop_hook, &vars);
	init_vars(&vars);
	render(&vars);
	mlx_loop(vars.mlx);
	//mlx_terminate(vars.mlx);
}
