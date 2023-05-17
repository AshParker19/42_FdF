/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:41:50 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/15 14:13:18 by anshovah         ###   ########.fr       */
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

	window = ft_new_window(WIDTH, HEIGHT, "FdF");
	if (!window.mlx_ptr || !window.win_ptr)
		return ;
	image.img_ptr = mlx_new_image(window.mlx_ptr, WIDTH, HEIGHT);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp,
			&image.line_len, &image.endian);
	ft_draw(&image, map);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr,
		image.img_ptr, 0, 0);
	mlx_hook(window.win_ptr, DestroyNotify, KeyPressMask, ft_exit, &window);
	mlx_loop(window.mlx_ptr);
}
