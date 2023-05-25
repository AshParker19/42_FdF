/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:59:13 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/25 18:12:04 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_error(int flag)
{
	ft_printf(CYAN "╔════════════════════════════════════════════════════╗"
		RESET "\n");
	ft_printf(CYAN "║                       " RED
		"ERROR!                       " CYAN "║" RESET "\n");
	if (flag == 1)
		ft_printf(CYAN "║" RED "             Wrong number of arguments!"
			"             " CYAN "║" RESET "\n");
	else if (flag == 2)
		ft_printf(CYAN "║" RED "               Wrong name of the map!"
			"               " CYAN "║" RESET "\n");
	ft_printf(CYAN "╟────────────────────────────────────────────────────╢"
		RESET "\n");
	ft_printf(CYAN "║" YELLOW " Please select a proper map name from "
		GREEN "./maps " YELLOW "folder" CYAN " ║" RESET "\n");
	ft_printf(CYAN "╟────────────────────────────────────────────────────╢"
		RESET "\n");
	ft_printf(CYAN "║" PURPLE "        Example of correct use: "
		GREEN "./fdf 42.fdf" CYAN "        ║" RESET "\n");
	ft_printf(CYAN "╚════════════════════════════════════════════════════╝"
		RESET "\n");
	return (1);
}

int	ft_scaling_factor(int map_h, int map_w)
{
	int			sf_w;
	int			sf_h;

	sf_h = HEIGHT / map_h;
	sf_w = WIDTH / map_w;
	if (sf_w < sf_h)
		return (sf_w);
	else
		return (sf_h);
}

int	ft_sf_altitude(t_point *head)
{
	t_point	*current;
	int		max_z;
	int		min_z;

	current = head;
	max_z = INT_MIN;
	min_z = INT_MAX;
	while (current)
	{
		if (current->z < min_z)
			min_z = current->z;
		if (current->z > max_z)
			max_z = current->z;
		current = current->next;
	}
	if (max_z == 0 && min_z == 0)
		return (-1);
	return (max_z - min_z);
}

void	ft_align_properly(t_point *head, int pc, t_coor coor)
{		
	t_point	*current;
	int		y_offset;
	int		x_offset;

	current = head;
	while (current)
	{	
		x_offset = (WIDTH - coor.x_coor) / 2 - (head->x_total / pc)
			+ (coor.x_coor / 2);
		y_offset = (HEIGHT - coor.y_coor) / 2;
		current->x += x_offset;
		current->y += y_offset;
		current = current->next;
	}
}

int	ft_color(t_point *node1, t_point *node2)
{
	if (node1->z == 0 && node2->z == 0)
		return (PINK);
	else if (node1->z > 0 && node2->z > 0)
		return (LIGHT_PURPLE);
	else if (node1->z < 0 && node2->z < 0)
		return (LIGHT_RED);
	else
		return (MINT);
}
