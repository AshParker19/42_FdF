/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:03:43 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/07 14:40:30 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	fdf(char *map_name)
{
	t_point	*map_info;

	map_info = NULL;
	map_info = ft_into_list(map_info, ft_start(map_name),
			(t_coor){0, 0, 0}, 0);
	ft_extend(map_info, map_info->sf, 0, 0);
	ft_on_screen(map_info);
}	

int	main(int ac, char *av[])
{
	if (ac == 2)
		fdf(av[1]);
	else
		return (ft_error(WRONG_AGR_NUM));
}
