/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:17:59 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/10 12:23:42 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_draw(t_img *img, t_point *map)
{
	ft_horizontal_lines(img, map);
	ft_vertical_lines(img, map);
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
			ft_line_drawer(img, (t_line){0x00FF00, save_next->y, save_next->x,
				save_next->next->y, save_next->next->x,
				abs((save_next->next->y) - (save_next->y)),
				abs((save_next->next->x) - (save_next->x))});
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
		save_down = save_next;
		while (save_down->down)
		{
			ft_line_drawer(img, (t_line){0x00FF00, save_next->y, save_next->x,
				save_down->down->y, save_down->down->x,
				abs((save_down->down->y) - (save_next->y)),
				abs((save_down->down->x) - (save_next->x))});
			save_down = save_down->down;
		}
		save_next = save_next->next;
	}
}

void	ft_line_drawer(t_img *data, t_line line)
{
	int	sx;
	int	sy;
	int	p1;
	int	p2;

	sx = ft_get_direction(line.x0, line.x1);
	sy = ft_get_direction(line.y0, line.y1);
	p1 = line.dx - line.dy;
	while (1)
	{
		ft_mlx_pixel_put(data, line.y0, line.x0, line.color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		p2 = 2 * p1;
		if (p2 > -(line.dy))
		{
			p1 -= line.dy;
			line.x0 += sx;
		}
		if (p2 < line.dx)
		{
			p1 += line.dx;
			line.y0 += sy;
		}
	}				
}

t_point	*ft_extend(t_point *head, int sf)
{
	t_point	*current;

	current = head;
	while (current)
	{
		current->y *= sf;
		current->x *= sf;
		// current->z *= sf;
		current = current->next;
	}
	return (head);
}
