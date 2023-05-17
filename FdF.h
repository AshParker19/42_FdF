/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:06:15 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/16 17:35:42 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>
# include <X11/ap_keysym.h>

// path to the maps
# define PATH "./maps/"

// errors
# define WRONG_AGR_NUM 1
# define WRONG_MAP_NAME 2

// max altitude range
#define MAR 100

// screen resolution parameters
// cluster 1
# define WIDTH  		1920
# define HEIGHT 		1080
// cluster 2
// # define WIDTH  		960
// # define HEIGHT 		540

// colors
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW  "\x1b[33m"
# define CYAN    "\x1b[36m"
# define PURPLE    "\x1b[35m"
# define RESET "\033[0m"

// coordinates
typedef struct s_point
{
	int				y;
	int				x;
	int				z;
	int				color;
	int				y_break;
	int				x_break;
	int				x_total;
	int				point_count;
	struct s_point	*next;
	struct s_point	*down;
}				t_point;

typedef struct s_coor
{
	int	y_coor;
	int	x_coor;
	int	z_coor;
}				t_coor;

// window
typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}				t_win;

// image
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

// line
typedef struct s_line
{
	int	color;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
}				t_line;

// linked lists functions
t_point	*ft_new_tail(t_point *head, t_coor coor, int col_max);
t_point	*ft_into_list(t_point *head, int fd, int y, int x);
t_point	*ft_row_connector(t_point *head, int num_nodes, int col_max, int sf);
void	ft_print_list(t_point *head);

// mlx functions
t_win	ft_new_window(int w, int h, char *str);
void	ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_on_screen(t_point *map);

//drawing functions
void	ft_draw(t_img *img, t_point *map);
void	ft_horizontal_lines(t_img *img, t_point *map);
void	ft_line_drawer(t_img *data, t_line line);
void	ft_vertical_lines(t_img *img, t_point *map);
void	ft_extend(t_point *node, int sf, int max_y, int max_x);

// hooks
int		ft_exit(t_win *window);

// utils
int		ft_nl(char *str);
int		ft_count_columns(char **matrix);
void	ft_free_matrix(char **matrix);
int		ft_start(char *map_name);
int		ft_get_direction(int a, int b);
int		ft_error(int flag);
int		ft_scaling_factor(int map_h, int map_w);
int		ft_sf_altitude(t_point *head);
void	ft_align_properly(t_point *head,
			int point_count, t_coor coor);
int		ft_color(t_point *node);

#endif

// command to execute Norminette to all the files but not to mlx folder
/* 
find . -maxdepth 1 -type f ! -name "Makefile"
! -name "mlx_linux" -exec norminette {} \;
*/