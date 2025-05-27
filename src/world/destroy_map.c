/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:57:36 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/24 15:10:37 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		free_str_arr(map->matrix);
	free(map);
}
