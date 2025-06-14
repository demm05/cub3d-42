/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:26:26 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/02 12:09:22 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

bool	flood_fill(t_map *map, int y, int x)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width)
	{
#if DEBUG
		printf("flood_fill: not met initial check: x(%d) y(%d)\n", x, y);
#endif
		return (0);
	}
	if (map->matrix[y][x] == '1' || map->matrix[y][x] == 'V')
		return (1);
	map->matrix[y][x] = 'V';
	if (!flood_fill(map, y + 1, x)
		|| !flood_fill(map, y - 1, x)
		|| !flood_fill(map, y, x + 1)
		|| !flood_fill(map, y, x - 1))
		return (0);
	return (1);
}
