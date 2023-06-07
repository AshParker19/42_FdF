/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llists_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:29:35 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/07 16:51:14 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_point	*ft_into_list(t_point *head, int fd, t_coor coor, int col_max)
{
	char	*line;
	char	**matrix;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		coor.x_coor = 0;
		matrix = ft_split(line, ' ');
		col_max = ft_count_columns(matrix);
		while (matrix[coor.x_coor] && coor.x_coor != col_max)
		{
			head = ft_new_tail(head, (t_coor){coor.y_coor, coor.x_coor,
					ft_atoi(matrix[coor.x_coor])}, col_max);
			coor.x_coor++;
		}
		ft_free_matrix(matrix);
		free (line);
		coor.y_coor++;
	}
	head->sf = ft_scaling_factor(coor.y_coor, coor.x_coor);
	head = ft_row_connector(head, (coor.y_coor * coor.x_coor), col_max);
	close(fd);
	return (head);
}

t_point	*ft_new_tail(t_point *head, t_coor coor, int col_max)
{
	t_point	*new_tail;
	t_point	*current;

	new_tail = ft_calloc(1, sizeof(t_point));
	new_tail->y = coor.y_coor;
	new_tail->x = coor.x_coor;
	new_tail->z = coor.z_coor;
	if (coor.x_coor == (col_max - 1))
		new_tail->x_break = coor.x_coor;
	new_tail->down = NULL;
	new_tail->next = NULL;
	if (!head)
		return (new_tail);
	else
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = new_tail;
		return (head);
	}	
}

t_point	*ft_row_connector(t_point *head, int num_nodes, int col_max)
{
	t_point	*current;
	t_point	*finder;
	int		last_possible;
	int		save;

	last_possible = num_nodes - col_max;
	current = head;
	while (last_possible--)
	{
		save = col_max;
		finder = current;
		while (save--)
			finder = finder->next;
		current->down = finder;
		current = current->next;
	}
	return (head);
}
