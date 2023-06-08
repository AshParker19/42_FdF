/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:17:59 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/08 13:35:45 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_draw(t_all *all)
{
	ft_horizontal_lines(all->img, all->map);
	ft_vertical_lines(all->img, all->map);
}

void	ft_horizontal_lines(t_img *img, t_point *map)
{
	t_point	*save_next;
	t_point	*save_down;

	save_down = map;
	while (save_down)
	{
		save_next = save_down;
		while (save_next->x_break == 0)
		{
			ft_line_drawer(img, (t_line){(save_next->y + map->shift_y),
				(save_next->x + map->shift_x),
				(save_next->next->y + map->shift_y),
				(save_next->next->x + map->shift_x),
				(save_next->color), (save_next->next->color)},
				(t_coor){0, 0, 0});
			save_next = save_next->next;
		}
		save_down = save_down->down;
	}
}

void	ft_vertical_lines(t_img *img, t_point *map)
{
	t_point	*save_next;
	t_point	*save_down;

	save_next = map;
	while (save_next)
	{
		save_down = save_next->down;
		if (save_down)
		{
			ft_line_drawer(img, (t_line){(save_next->y + map->shift_y),
				(save_next->x + map->shift_x), (save_down->y + map->shift_y),
				(save_down->x + map->shift_x),
				(save_next->color), (save_down->color)},
				(t_coor){0, 0, 0});
		}
		save_next = save_next->next;
	}
}

void	ft_line_drawer(t_img *data, t_line line, t_coor coor)
{
	double	dy;
	double	dx;
	double	y;
	double	x;

	dx = line.x1 - line.x0;
	dy = line.y1 - line.y0;
	if (fabs(dx) > fabs(dy))
		coor.y_coor = fabs(dx);
	else
		coor.y_coor = fabs(dy);
	x = line.x0;
	y = line.y0;
	coor.x_coor = 0;
	while (coor.x_coor <= coor.y_coor)
	{
		ft_mlx_pixel_put(data, (int)y, (int)x, line.base_color);
		line.base_color = ft_gradient(line.base_color, line.end_color);
		x += (dx / coor.y_coor);
		y += (dy / coor.y_coor);
		coor.x_coor++;
	}
}

void	ft_extend(t_point *head, int sf, int max_y, int max_x)
{
	t_point		*current;
	int			range;
	float		sf_z;

	range = ft_altitude(head);
	sf_z = AM / (float)range;
	head->sf_z = sf_z;
	current = head;
	while (current)
	{
		current->x *= sf / 1.6;
		current->y *= sf / 1.6;
		current->z *= sf_z;
		current->orig_x = current->x;
		current->orig_y = current->y;
		current->color = ft_color(current->z);
		if (current->x > max_x)
			max_x = current->x;
		if (current->y > max_y)
			max_y = current->y;
		current = current->next;
	}
	head->max_y = max_y;
	head->max_x = max_x;
}
