/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:38:09 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/08 11:13:15 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_exit(t_all *all)
{
	if (all->win)
	{
		mlx_destroy_image(all->win->mlx_ptr, all->img->img_ptr);
		mlx_destroy_window(all->win->mlx_ptr, all->win->win_ptr);
		mlx_destroy_display(all->win->mlx_ptr);
		free (all->win->mlx_ptr);
		ft_free_everything(all->map, all);
	}
	exit(0);
}

void	ft_zoom_in(int keycode, t_all *all)
{
	t_point	*current;
	double	x_center;
	double	y_center;

	x_center = all->map->max_x / 2.0;
	y_center = all->map->max_y / 2.0;
	current = all->map;
	if (keycode == ZOOM_IN)
	{
		while (current)
		{
			current->y = (current->y - y_center) * 1.1 + y_center;
			current->x = (current->x - x_center) * 1.1 + x_center;
			current = current->next;
		}
	}
	else if (keycode == ZOOM_OUT)
		ft_zoom_out(all->map, y_center, x_center);
	ft_destroy_and_build(all);
}

void	ft_zoom_out(t_point *map, int y_center, int x_center)
{
	t_point	*current;

	current = map;
	while (current)
	{
		current->y = (current->y - y_center) / 1.1 + y_center;
		current->x = (current->x - x_center) / 1.1 + x_center;
		current = current->next;
	}
}

void	ft_translation(int keycode, t_all *all)
{
	if (keycode == 'w')
		all->map->shift_y -= 10;
	else if (keycode == 's')
		all->map->shift_y += 10;
	else if (keycode == 'd')
		all->map->shift_x += 10;
	else if (keycode == 'a')
		all->map->shift_x -= 10;
	ft_destroy_and_build(all);
}

int	ft_keys(int keycode, t_all *all)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_image(all->win->mlx_ptr, all->img->img_ptr);
		mlx_destroy_window(all->win->mlx_ptr, all->win->win_ptr);
		mlx_destroy_display(all->win->mlx_ptr);
		free (all->win->mlx_ptr);
		ft_free_everything(all->map, all);
		exit(0);
	}
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW
		|| keycode == UP_ARROW || keycode == DOWN_ARROW)
		ft_rotation(keycode, all);
	else if (keycode == 'p')
		ft_projection(all);
	else if (keycode == 'w' || keycode == 'd'
		|| keycode == 's' || keycode == 'a')
		ft_translation(keycode, all);
	else if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		ft_zoom_in(keycode, all);
	else if (keycode == LEVEL_UP || keycode == LEVEL_DOWN)
		ft_level(keycode, all);
	return (0);
}
