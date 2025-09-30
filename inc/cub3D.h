/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/09/30 16:09:13 by tschulle         ###   ########.fr       */
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

typedef struct s_config
{
	int		no_set;
	int		so_set;
	int		we_set;
	int		ea_set;
	int		floor_set;
	int		ceil_set;
	int		map_set;
	char	*texture_no;	// path to north texture
	char	*texture_so;	// path to south texture
	char	*texture_we;	// path to west texture
	char	*texture_ea;	// path to east texture

	int		floor_color;
	int		ceiling_color;

	char	**map;			// 2D array representing the map
	int		map_width;		// length of the longest row (number of columns)
	int		map_height;		// number of rows

	int		player_x;		// x coordinate
	int		player_y;		// y coordinate
	char	player_dir;		// 'N', 'S', 'E', or 'W'
}	t_config;

 typedef struct s_vars
 {
	mlx_t	*mlx;
	mlx_image_t	*background;
	mlx_image_t *minimap;
	t_config	config;
 }	t_vars;

//main.c
int		check_file(char *file);
void	init_data(t_config *data);

//parser.c
int		starts_with(char *line, char *str);
void	parser(int fd, t_config *data);
int		check_valid_path(char *path);
int		parse_texture(char *line, t_config *data);
int		check_validity_input(char *str);
int		color_to_hex(int red, int green, int blue);
int		color_str_to_int(char *str);
int		parse_color(char *line, t_config *data);
void	parse_element(char *line, t_config *data);

 void	ft_hook(mlx_key_data_t keydata, void *param);
 int	render_background(t_vars *vars);
 int	render_minimap(t_vars *vars);
#endif



