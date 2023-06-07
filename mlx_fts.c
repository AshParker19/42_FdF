/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:41:50 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/07 14:46:04 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_win	ft_new_window(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dest;

	if (y >= 0 && x >= 0 && y < HEIGHT && x < WIDTH)
	{
		dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dest = color;
	}
}

void	ft_on_screen(t_point *map)
{
	t_win	window;
	t_img	image;
	t_all	*all;

	all = ft_calloc(1, (sizeof(t_all)));
	window = ft_new_window(WIDTH, HEIGHT, "FdF");
	if (!window.mlx_ptr || !window.win_ptr)
		return ;
	image.img_ptr = mlx_new_image(window.mlx_ptr, WIDTH, HEIGHT);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp,
			&image.line_len, &image.endian);
	all->win = &window;
	all->map = map;
	all->img = &image;
	all->rot = (t_rot){0, 0};
	map->shift_x = (WIDTH - map->max_x) / 2;
	map->shift_y = (HEIGHT - map->max_y) / 2;
	ft_draw(all);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr,
		image.img_ptr, 0, 0);
	mlx_hook(window.win_ptr, DestroyNotify, KeyPressMask, ft_exit, all);
	mlx_key_hook(window.win_ptr, ft_keys, all);
	mlx_loop(window.mlx_ptr);
}
