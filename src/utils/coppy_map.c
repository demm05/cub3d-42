/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coppy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:32:27 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/16 16:32:49 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

static char	**coppy_matrix(char	**matrix, int height)
{
	char	**coppy;
	int		i;

	if (!matrix)
		return (NULL);
	coppy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!coppy)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		coppy[i] = ft_strdup(matrix[i]);
		i++;
	}
	coppy[i] = NULL;
	return (coppy);
}

t_map	*coppy_map(t_map *map)
{
	t_map	*coppy;

	if (!map)
		return (NULL);
	coppy = malloc(sizeof(t_map));
	if (!coppy)
		return (NULL);
	coppy->matrix = coppy_matrix(map->matrix, map->height);
	if (!coppy->matrix)
	{
		free(coppy);
		return (NULL);
	}
	coppy->width = map->width;
	coppy->height = map->height;
	return (coppy);
}