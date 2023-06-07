/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:56:18 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/07 21:46:40 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_columns(char **matrix)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (matrix[i])
	{
		if (ft_nl(matrix[i]))
			count++;
		i++;
	}
	return (count);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

int	ft_start(char *map_name)
{
	int		fd;
	char	*full_path;

	full_path = ft_strjoin(PATH, map_name);
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
		exit(ft_error(WRONG_MAP_NAME));
	else
		ft_instruction();
	free (full_path);
	return (fd);
}

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
