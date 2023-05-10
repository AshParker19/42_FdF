/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llists_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:29:35 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/10 12:02:36 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_point	*ft_new_tail(t_point *head, t_coor coor, int col_max)
{
	t_point	*new_tail;
	t_point	*current;

	new_tail = ft_calloc(1, sizeof(t_point));
	new_tail->y = coor.y_coor;
	new_tail->x = coor.x_coor;
	new_tail->z = coor.z_coor;
	if (coor.x_coor == (col_max - 1))
	{
		new_tail->y_break = coor.y_coor;
		new_tail->x_break = coor.x_coor;
	}
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

t_point	*ft_into_list(t_point *head, int fd, int y, int x)
{
	char	*line;
	char	**matrix;
	int		col_max;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		x = 0;
		matrix = ft_split(line, ' ');
		col_max = ft_count_columns(matrix);
		while (matrix[x] && x != col_max)
		{
			head = ft_new_tail(head,
					(t_coor){y, x, ft_atoi(matrix[x])}, col_max);
			x++;
		}
		ft_free_matrix(matrix);
		y++;
	}
	head = ft_extend(head, ft_scaling_factor(y, x, HEIGHT, WIDTH));
	head = ft_row_connector(head, (y * x), col_max);
	close(fd);
	return (head);
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

void	ft_print_list(t_point *head)
{
	t_point	*current;

	current = head;
	while (current != NULL)
	{
		printf("Node (%d, %d, %d):\n", current->y, current->x, current->z);
		if (current->x_break)
			printf(" BREAK Y %d | BREAK X %d\n",
				current->y_break, current->x_break);
		printf("  - Down Pointer: ");
		if (current->down != NULL)
			printf("(%d, %d, %d)\n", current->down->y,
				current->down->x, current->down->z);
		else
			printf("NULL\n");
		printf("  - Next Pointer: ");
		if (current->next != NULL)
			printf("(%d, %d, %d)\n", current->next->y,
				current->next->x, current->next->z);
		else
			printf("NULL\n");
		printf("\n");
		current = current->next;
	}
}
