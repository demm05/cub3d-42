/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:04:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/10 12:45:28 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

MAYBE_INLINE int map_get(t_map *map, int x, int y)
{
	return (map->matrix[y % map->height][x % map->width] - '0');
}

MAYBE_INLINE void	map_set(t_map *map, int x, int y, int c)
{
	map->matrix[y][x] = c + '0';
}
