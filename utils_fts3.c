/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:42:39 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/25 18:12:12 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_free_everything(t_point *head, t_all *all)
{
	t_point	*current;
	t_point	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free (current);
		current = next;
	}
	free (all);
}
