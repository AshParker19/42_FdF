/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_fts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:26:28 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/07 15:23:38 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_rotate_x(t_point *map, double angle, double y, double z)
{
	double	y_center;
	double	z_center;
	double	new_y;
	double	new_z;
	t_point	*current;

	y_center = (map->max_y) / 2.0;
	z_center = (map->max_z) / 2.0;
	current = map;
	while (current)
	{
		y = current->y - y_center;
		z = current->z - z_center;
		new_y = y * cos(angle) + z * sin(angle);
		new_z = -y * sin(angle) + z * cos(angle);
		current->y = new_y + y_center;
		current->z = new_z + z_center;
		current = current->next;
	}
}

void	ft_rotate_y(t_point *map, double angle, double x, double z)
{
	double	x_center;
	double	z_center;
	double	new_x;
	double	new_z;
	t_point	*current;

	x_center = (map->max_x) / 2.0;
	z_center = (map->max_z) / 2.0;
	current = map;
	while (current)
	{
		x = current->x - x_center;
		z = current->z - z_center;
		new_x = x * cos(angle) + z * sin(angle);
		new_z = -x * sin(angle) + z * cos(angle);
		current->x = new_x + x_center;
		current->z = new_z + z_center;
		current = current->next;
	}
}

void	ft_rotation(int keycode, t_all *all)
{
	if (keycode == LEFT_ARROW)
		all->rot.y_rot = -0.1;
	else if (keycode == RIGHT_ARROW)
		all->rot.y_rot = 0.1;
	else if (keycode == UP_ARROW)
		all->rot.x_rot = -0.1;
	else if (keycode == DOWN_ARROW)
		all->rot.x_rot = 0.1;
	ft_rotate_y(all->map, all->rot.y_rot, 0, 0);
	ft_rotate_x(all->map, all->rot.x_rot, 0, 0);
	all->rot.y_rot = 0.0;
	all->rot.x_rot = 0.0;
	ft_delete_and_build(all);
}
