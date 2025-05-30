/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:09 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/30 15:12:13 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

static char	**coppy_matrix(char	**matrix, int height)
{
	char	**coppy;
	int		i;

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

static t_map	*coppy_map(t_map *map)
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

static bool	check_line(t_map *map, int j)
{
	int	i;

	i = 0;
	while (map->matrix[j][i])
	{
		if (map->matrix[j][i] == 'N' || map->matrix[j][i] == 'S'
			|| map->matrix[j][i] == 'E' || map->matrix[j][i] == 'W')
		{
			if (map->player_pos.x != 0 && map->player_pos.y != 0)
				return (ft_putendl_fd(RED "Error" RESET
						": To many players", STDERR_FILENO), 0);
			map->player_pos.x = i;
			map->player_pos.y = j;
		}
		i++;
	}
	return (1);
}

static bool	check_player(t_map *map)
{
	int	j;

	j = 0;
	if (!map)
		return (0);
	while (map->matrix[j])
	{
		if (!check_line(map, j))
			return (0);
		j++;
	}
	if (!map->player_pos.x && !map->player_pos.y)
		return (ft_putendl_fd(RED "Error" RESET
				": Player not found", STDERR_FILENO), 0);
	return (1);
}

bool	check_map(t_map *map)
{
	t_map	*tmp;
	bool	status;

	if (!map)
		return (0);
	tmp = coppy_map(map);
	if (!tmp)
		return (0);
	status = flood_fill(tmp, 10, 27);
	destroy_map(tmp);
	if (!status)
		ft_putendl_fd(RED "Error" RESET ": Map not closed", STDERR_FILENO);
	if (!check_player(map))
		return (0);
	return (status);
}
