/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:38:09 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/25 17:44:45 by anshovah         ###   ########.fr       */
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

int	ft_esc(int keycode, t_all *all)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(all->win->mlx_ptr, all->img->img_ptr);
		mlx_destroy_window(all->win->mlx_ptr, all->win->win_ptr);
		mlx_destroy_display(all->win->mlx_ptr);
		free (all->win->mlx_ptr);
		ft_free_everything(all->map, all);
		exit(0);
	}
	return (0);
}
