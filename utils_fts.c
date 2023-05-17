/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:56:18 by anshovah          #+#    #+#             */
/*   Updated: 2023/05/13 13:51:54 by anshovah         ###   ########.fr       */
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
	free (full_path);
	return (fd);
}

int	ft_get_direction(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}
