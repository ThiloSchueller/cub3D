/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/07 13:52:35 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define HEIGHT 600
# define WIDTH 800
# define SCALE 10
# define PI 3.1415926535
# define FOV 60
# define MMSIZE 200.0
# define EPSILON 0.001
# define ERROR_MLX 10
# define ERROR_MALLOC 11
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../mlx/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

typedef struct s_config
{
	int		stop;
	int		map_before;
	int		no_set;
	int		so_set;
	int		we_set;
	int		ea_set;
	int		floor_set;
	int		ceil_set;
	int		map_set;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;

	int		floor_color;
	int		ceiling_color;

	char	**map;
	int		map_width;
	int		map_height;

	int		x_position;
	int		y_position;
	char	player_dir;
}	t_config;

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*north;
	mlx_image_t	*south;
	mlx_image_t	*west;
	mlx_image_t	*east;
}	t_image;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fpoint
{
	double	x;
	double	y;
}	t_fpoint;

typedef struct s_hit_info
{
	double			distance;
	double			percent_of_hit;
	double			wall_height;
	bool			vertical_hit;
	mlx_texture_t	*texture;
}	t_hit_info;

typedef struct s_vars
{
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*minimap;
	mlx_image_t	*walls;
	t_config	*config;
	char		**smap;
	char		**cmap;
	int			smap_width;
	int			smap_height;
	t_fpoint	scale;
	double		view_angle;
	t_point		pos;
	t_fpoint	fpos;
	t_image		images;
	t_texture	*textures;
	bool		mmswitch;
	t_hit_info	hit_info;
}	t_vars;

//smap scaled map
//cmap collision map

//check_arg_file.c
t_config		*check_arg(int argc);
int				check_file(char *file);
t_config		*check_arg_map(int argc, char *argv[]);

//parser
//main.c
void			clean_after_x(t_vars *vars);
void			init_after_mlx(t_vars *vars);
//parser_colours.c
int				check_validity_input(char *str);
int				color_to_hex(int red, int green, int blue);
char			**array_color(char *str);
int				color_str_to_int(char *str);
int				parse_color(char *line, t_config *data);
//parser_helper.c
char			*remove_space_tab_before(char *line);
char			*remove_space_tab_between(char *line);
int				starts_with(char *line, char *str);
char			*ft_strdup_no_newline_map(const char *s1);
char			*ft_strdup_no_newline(const char *s1);
//parser_map.c
int				is_map_line(char *line);
void			parse_map(char *line, t_config *data);
void			free_map(char **map);
void			create_empty_map(t_config *data);
void			print_map(t_config *data);
//parser_textures.c
int				check_valid_path(char *path);
int				parse_texture(char *line, t_config *data);
//parser.c
int				copy_line(char *dst, char *src, t_config *data);
int				compare_update_map(char *line, t_config *data);
void			parser_map_2nd_round(t_config *data, char *file);
void			parser(int fd, t_config *data, char *file);
void			parse_element(char *line, t_config *data);
//parser_checker_map.c
char			**map_copy(t_config *data);
void			print_copy(char **map);
void			check_map(t_config *data);
int				check_conditions_map(char **map, t_config *data);
//parser_conditions_map.c
int				check_outside_walls(char **map);
int				check_last_wall(char **map);
int				player_position(char **map);
int				zero_touch_space(char **map);
int				player(char **map, t_config *data);
//images.c
void			ft_get_textures(t_vars *vars);
//init.c
void			init_data(t_config *data);
void			free_data(t_config *data);
void			init_vars(t_vars *vars);
void			set_view_angle(t_vars *vars);
//hook.c
void			ft_key_hook(mlx_key_data_t keydata, void *param);
void			ft_loop_hook(void *param);
t_fpoint		vec_add(t_fpoint a, t_fpoint b);
t_fpoint		normalise_vec_length(t_fpoint d);
//key_arrows.c
void			left_key(t_vars *vars);
void			right_key(t_vars *vars);
//key_wasd.c
t_fpoint		w_key(t_vars *vars);
t_fpoint		s_key(t_vars *vars);
t_fpoint		a_key(t_vars *vars);
t_fpoint		d_key(t_vars *vars);
//render.c
int				render(t_vars *vars);
int				render_background(t_vars *vars);
int				render_minimap(t_vars *vars);
double			initialize_values(double *jump, t_vars *vars, int x);
int				render_walls(t_vars *vars);
//small_render.c
void			overwrite_previous_frame(t_vars *vars);
mlx_texture_t	*right_texture(t_vars *vars, double angle, bool vertical_hit);
mlx_texture_t	*left_texture(t_vars *vars, double angle, bool vertical_hit);
mlx_texture_t	*define_texture(t_vars *vars, double angle, bool vertical_hit);
uint32_t		get_color(t_vars *vars, int ye, double jump,
					double begin_texture);
//minimap.c
t_fpoint		get_scaling_minimap(t_vars *vars);
int				render_minimap_ray(t_vars *vars, double angle);
int				render_minimap_view(t_vars *vars);
void			fill_smap(t_vars *vars, int x, int y, char ***smap);
char			**calc_smap(t_vars *vars);
//helpers.c
bool			is_player_char(char c);
void			ft_free_array(char **a);
void			free_array(char **array);
int				parse_texture_color_before(t_config *data);
void			check_map_before(t_config *data);
//exit.c
int				ft_exit(int code, t_vars *vars);
void			ft_free_vars(t_vars *vars);
//calc1.c
t_hit_info		get_hit_info(t_vars *vars, int x);
double			calculate_angle(t_vars *vars, int x);
t_hit_info		steep_angles(t_vars *vars, double angle);
t_hit_info		calculate_distance(t_vars *vars, double angle);
t_fpoint		calc_intersections(t_vars *vars, double angle,
					double x_to_hit, double y_to_hit);
//calc2.c
double			distance_two_points(t_fpoint p, t_fpoint q);
double			normalise_angle(double angle);
bool			confirm_hit_x(double x_to_hit, double y_hit,
					double angle, t_vars *vars);
bool			confirm_hit_y(double x_hit, double y_to_hit,
					double angle, t_vars *vars);
void			ray_walk_loop(t_vars *vars, double angle,
					t_fpoint *ray_pos, t_hit_info *hit_info);
//directions.c
bool			facing_right(double angle);
bool			facing_left(double angle);
bool			facing_up(double angle);
bool			facing_down(double angle);
//lines.c
t_fpoint		lines_to_hit(t_fpoint point, double angle);
//bool		forbidden_square(t_vars *vars,double dx,double dy, double angle);
t_fpoint		lines_to_hit_up(t_fpoint point, double angle);
t_fpoint		lines_to_hit_down(t_fpoint point, double angle);
//hit_steep_angles.c
t_hit_info		hit_top(t_vars *vars, double angle);
t_hit_info		hit_right(t_vars *vars, double angle);
t_hit_info		hit_left(t_vars *vars, double angle);
t_hit_info		hit_bot(t_vars *vars, double angle);
//move_helpers.c
double			ox(double angle);
double			oy(double angle);
bool			confirm_move_x(double x_to_hit, double y_hit,
					double angle, t_vars *vars);
bool			confirm_move_y(double x_hit, double y_to_hit,
					double angle, t_vars *vars);
//move.c
void			move_2d(t_vars *vars, t_fpoint d);
void			move_over_one_line(t_vars *vars, double angle, t_fpoint new);
void			move_over_two_lines(t_vars *vars, double angle, t_fpoint new);
void			second_step(t_vars *vars, double angle, t_fpoint new);
//collisionmap.c
char			**calc_cmap(t_vars *vars);
void			fill_cmap(t_vars *vars, int x, int y, char ***cmap);

#endif
