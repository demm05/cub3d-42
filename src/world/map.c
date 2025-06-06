/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:04:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/28 17:04:15 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

MAYBE_INLINE char	map_get(t_world *wrd, int x, int y)
{
	return (wrd->map->matrix[y][x]);
}

MAYBE_INLINE void	map_set(t_world *wrd, int x, int y, int c)
{
	wrd->map->matrix[y][x] = c;
}
