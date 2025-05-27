/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:58:56 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/27 11:07:09 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

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
