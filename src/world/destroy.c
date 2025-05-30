/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:58:56 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/30 12:48:45 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		free_str_arr(map->matrix);
	map->matrix = NULL;
}

void	world_destroy(void *mlx_ptr, t_world *world)
{
	if (!world)
		return ;
	buffer_destroy(mlx_ptr, &world->ea);
	buffer_destroy(mlx_ptr, &world->no);
	buffer_destroy(mlx_ptr, &world->so);
	buffer_destroy(mlx_ptr, &world->we);
	destroy_map(world->map);
}
