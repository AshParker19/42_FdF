/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:59:13 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/08 18:02:55 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_instruction(void)
{
	ft_printf(CYAN "╒≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡"
		"≡≡≡≡≡≡≡╕" RESET"\n" CYAN "│" YELLOW "                   "
		"NAVIGATION AND CONTROLS" "                   " CYAN "│" RESET "\n"
		CYAN "╘≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡"
		"≡≡≡≡≡≡≡╛" RESET "\n" CYAN "╔═══════════════════════════════════════════"
		"══════════════════╗" RESET "\n" CYAN "║" PURPLE "      "
		GREEN "P --->" PURPLE "  switch the image projection to isometric      "
		CYAN " ║" RESET "\n" CYAN "║" PURPLE "        Press one more time to swi"
		"tch back to paralel        " CYAN "║" RESET "\n" CYAN "╟───────────────"
		"──────────────────────────────────────────────╢" RESET "\n" CYAN "║"
		GREEN "          1 --> " PURPLE "zoom in              " GREEN "2 --> "
		PURPLE "zoom out          " CYAN "║" RESET "\n" CYAN "╟───────────────"
		"──────────────────────────────────────────────╢" RESET "\n" CYAN "║"
		PURPLE "                         Translation                         "
		CYAN "║" RESET "\n" CYAN "║" GREEN "  W -->" PURPLE "  UP    "
		GREEN "S -->" PURPLE "  DOWN     " GREEN "D -->" PURPLE "  RIGHT    "
		GREEN "A -->" PURPLE "  LEFT  " CYAN " ║" RESET "\n" CYAN
		"╟─────────────────────────────────────────────────────────────╢"
		RESET "\n" CYAN "║" PURPLE "         x-axis rotation              y-axi"
		"s rotation" CYAN "        ║" RESET "\n" CYAN "║" GREEN "         "
		"LEFT/RIGHT ARROW       "
		"      UP/DOWN ARROW" CYAN "          ║" RESET "\n" CYAN "╟─────────────"
		"────────────────────────────────────────────────╢" RESET "\n" CYAN "║");
	ft_instruction2();
}

void	ft_instruction2(void)
{
	ft_printf(PURPLE "                     Change the altitude" CYAN
		"                     ║" RESET "\n" CYAN "║"
		GREEN "   3 --> " PURPLE "increase volume             "
		GREEN "4 --> " PURPLE "decrease volume" CYAN "   ║" RESET "\n"
		CYAN "║" RED "Do not use if any other changes were made"
		"(undefined behavior)"CYAN "║\n"
		CYAN "╚═════════════════════════════════════════════════════════════╝"
		RESET "\n");
}

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

int	ft_altitude(t_point *head)
{
	t_point	*current;
	int		max_z;
	int		min_z;

	current = head;
	max_z = -1000;
	min_z = 1000;
	while (current)
	{
		if (current->z < min_z)
			min_z = current->z;
		if (current->z > max_z)
			max_z = current->z;
		current = current->next;
	}
	head->max_z = max_z;
	head->min_z = min_z;
	if (max_z == 0 && min_z == 0)
		return (-1);
	return (max_z - min_z);
}
