/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/09/30 15:11:36 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

 #define HEIGHT 600
 #define WIDTH 800
 #include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include "../mlx/include/MLX42/MLX42.h"
 #include "../libft/libft.h"
 #include "../libft/ft_printf.h"
 #include "../libft/get_next_line.h"

 typedef struct s_vars
 {
	mlx_t	*mlx;
	mlx_image_t	*background;
	mlx_image_t *minimap;
 }	t_vars;

 void	ft_hook(mlx_key_data_t keydata, void *param);
 int	render_background(t_vars *vars);
 int	render_minimap(t_vars *vars);
 
#endif