/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_fts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:42:39 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/07 16:24:02 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_reset(t_all *tall)
{
	int		max_x;
	int		max_y;
	int		center_x;
	int		center_y;
	t_point	*current;

	max_x = tall->map->max_x;
	max_y = tall->map->max_y;
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	current = tall->map;
	while (current)
	{
		current->x = current->orig_x;
		current->y = current->orig_y;
		current = current->next;
	}
	current = tall->map;
	while (current)
	{
		current->x += center_x - max_x / 2 - (WIDTH - tall->map->max_x) / 2;
		current->y += center_y - max_y / 2 - (HEIGHT - tall->map->max_y) / 2;
		current = current->next;
	}
}

void	ft_isometric(t_all *tall)
{
	t_point	*current;
	int		orig_x;
	int		orig_y;

	current = tall->map;
	while (current)
	{
		orig_x = current->orig_x;
		orig_y = current->orig_y;
		if (tall->map->max_x > 50 && tall->map->max_x < 800)
		{
			current->x = (orig_x - orig_y) * cos(0.6) + 400;
			current->y = (orig_x + orig_y) * sin(0.6) - current->z;
		}
		else
		{
			current->x = (orig_x - orig_y) * cos(0.6)
				+ (WIDTH - tall->map->max_x) / 2;
			current->y = (orig_x + orig_y) * sin(0.6) - current->z - 150;
		}
		current = current->next;
	}
}

void	ft_level(int keycode, t_all *all)
{
	t_point	*current;

	current = all->map;
	if (keycode == LEVEL_UP)
	{
		while (current)
		{	
			if (current->z < all->map->max_z * 20)
				current->z *= 1.1;
			current = current->next;
		}
		ft_isometric(all);
	}
	else if (keycode == LEVEL_DOWN)
	{
		while (current)
		{
			current->z /= 1.1;
			current = current->next;
		}
		ft_isometric(all);
	}
	ft_delete_and_build(all);
}

void	ft_delete_and_build(t_all *all)
{
	ft_bzero(all->img->addr, (HEIGHT * WIDTH * sizeof(all->img->bpp)));
	ft_draw(all);
	mlx_put_image_to_window(all->win->mlx_ptr, all->win->win_ptr,
		all->img->img_ptr, 0, 0);
}
