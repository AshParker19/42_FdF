/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:06:15 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/08 16:31:31 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// path to the maps
# define PATH "./maps/"

// errors
# define WRONG_AGR_NUM 1
# define WRONG_MAP_NAME 2

// altitude multiplier
# define AM 100

// screen resolution parameters
// cluster 1
# define WIDTH 1920
# define HEIGHT 1180
// cluster 2
// # define WIDTH  		1260
// # define HEIGHT 		940

// colors for the image
# define PINK	 		0xFF69B4
# define LIGHT_RED		0xFFC0C0
# define MINT			0xAAFFC3
# define LEMON			0xFFFF99

// colors for the error message
# define GREEN 			"\033[0;32m"
# define RED 			"\033[0;31m"
# define YELLOW 		"\x1b[33m"
# define CYAN 			"\x1b[36m"
# define PURPLE 		"\x1b[35m"
# define RESET 			"\033[0m"

// keys
# define ESCAPE			65307
# define LEFT_ARROW		65361
# define RIGHT_ARROW 	65363
# define UP_ARROW		65362
# define DOWN_ARROW		65364
# define ZOOM_IN		49
# define ZOOM_OUT		50
# define LEVEL_UP		51
# define LEVEL_DOWN		52

// coordinates
typedef struct s_point
{
	double			y;
	double			x;
	double			z;
	int				x_break;
	int				sf;
	int				sf_z;
	int				max_y;
	int				max_x;
	int				max_z;
	int				min_z;
	int				iso_mod;
	int				orig_y;
	int				orig_x;
	int				shift_y;
	int				shift_x;
	int				color;
	struct s_point	*next;
	struct s_point	*down;
}					t_point;

typedef struct s_coor
{
	int				y_coor;
	int				x_coor;
	int				z_coor;
}					t_coor;

// window
typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
}					t_win;

// image
typedef struct s_img
{
	void			*img_ptr;
	char			*addr;
	int				bpp;
	int				endian;
	int				line_len;
}					t_img;

// line
typedef struct s_line
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				base_color;
	int				end_color;
}					t_line;

// rotation
typedef struct s_rot
{
	double			y_rot;
	double			x_rot;
}					t_rot;

// pointers to everything
typedef struct s_all
{
	t_win			*win;
	t_point			*map;
	t_img			*img;
	t_rot			rot;
}					t_all;

// linked lists functions
t_point		*ft_new_tail(t_point *head, t_coor coor, int col_max);
t_point		*ft_into_list(t_point *head, int fd,
				t_coor coor, int col_max);
t_point		*ft_row_connector(t_point *head, int num_nodes, int col_max);
void		ft_free_everything(t_point *head, t_all *all);

// mlx functions
t_win		ft_new_window(int w, int h, char *str);
void		ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void		ft_on_screen(t_point *map);

// drawing functions
void		ft_draw(t_all *tall);
void		ft_line_drawer(t_img *data, t_line line, t_coor coor);
void		ft_horizontal_lines(t_img *img, t_point *map);
void		ft_vertical_lines(t_img *img, t_point *map);
void		ft_extend(t_point *node, int sf, int max_y, int max_x);

// hooks
int			ft_exit(t_all *all);
int			ft_keys(int keycode, t_all *all);
void		ft_projection(t_all *all);
void		ft_translation(int keycode, t_all *all);
void		ft_zoom_in(int keycode, t_all *all);
void		ft_zoom_out(t_point *map, int y_center, int x_center);
void		ft_level(int keycode, t_all *all);
void		ft_destroy_and_build(t_all *all);

// // rotation
void		ft_rotation(int keycode, t_all *all);
void		ft_rotate_y(t_point *map, double angle, double x, double z);
void		ft_rotate_x(t_point *map, double angle, double y, double z);

// utils
void		ft_instruction(void);
void		ft_instruction2(void);
int			ft_nl(char *str);
int			ft_count_columns(char **matrix);
void		ft_free_matrix(char **matrix);
int			ft_start(char *map_name);
int			ft_color(float z);
int			ft_gradient(int base_color, int end_color);
int			ft_error(int flag);
int			ft_scaling_factor(int map_h, int map_w);
int			ft_altitude(t_point *head);
void		ft_isometric(t_all *tall);
void		ft_reset(t_all *tall);

#endif
