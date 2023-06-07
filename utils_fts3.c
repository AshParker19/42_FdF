/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:40:54 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/07 21:57:13 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_color(float z)
{
	if (z == 0)
		return (MINT);
	else if (z < 0)
		return (LIGHT_PURPLE);
	else
		return (PINK);
}

int	ft_gradient(int base_color, int end_color)
{
	int	r;
	int	g;
	int	b;
	int	move;

	move = 1;
	r = (base_color >> 16) & 0xFF;
	if (r < ((end_color >> 16) & 0xFF))
		r += move;
	else if (r > ((end_color >> 16) & 0xFF))
		r -= move;
	g = (base_color >> 8) & 0xFF;
	if (g < ((end_color >> 8) & 0xFF))
		g += move;
	else if (g > ((end_color >> 8) & 0xFF))
		g -= move;
	b = (base_color & 0xFF);
	if (b < (end_color & 0xFF))
		b += move;
	else if (b > (end_color & 0xFF))
		b -= move;
	return ((r << 16) | (g << 8) | b);
}

void	ft_projection(t_all *all)
{
	if (all->map->iso_mod == 1)
	{
		all->map->iso_mod = 0;
		ft_reset(all);
	}
	else
	{
		all->map->iso_mod = 1;
		ft_isometric(all);
	}
	ft_delete_and_build(all);
}
