/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:59:13 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/09 22:12:07 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_error(void)
{
	ft_printf(CYAN "╔═══════════════════════════════════════════════════╗"
		RESET "\n");
	ft_printf(CYAN "║                       " RED
		"ERROR!	                    "
		CYAN "║" RESET "\n");
	ft_printf(CYAN "╟───────────────────────────────────────────────────╢"
		RESET "\n");
	ft_printf(CYAN "║" YELLOW "    	      Oops! Something went wrong!	"
		CYAN "    ║" RESET "\n");
	ft_printf(CYAN "║" YELLOW " Please select a proper map name from "
		GREEN "/maps " YELLOW "folder" CYAN " ║" RESET "\n");
	ft_printf(CYAN "╚═══════════════════════════════════════════════════╝"
		RESET "\n");
	return (1);
}

int	ft_scaling_factor(int map_h, int map_w, int screen_h, int screen_w)
{
	int	sf_w;
	int	sf_h;

	sf_w = screen_w / map_w;
	sf_h = screen_h / map_h;
	if (sf_w < sf_h)
		return (sf_w);
	else
		return (sf_h);
}
