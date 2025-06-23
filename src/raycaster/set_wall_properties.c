/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_properties.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:46 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:46 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_private.h"
#include <math.h>

MAYBE_INLINE void	ray_set_wall_prop(t_engine *eng, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_hit = eng->camera.pos.y + ray->wall_dist * ray->direction.y;
	else
		ray->wall_hit = eng->camera.pos.x + ray->wall_dist * ray->direction.x;
	ray->wall_hit -= floor(ray->wall_hit);
	ray->texture = sprite_get_img(&eng->textures.walls,
		map_get(eng->map, ray->map.x, ray->map.y) - 1);
	ray->x_on_tex = (int)(ray->wall_hit * (double)ray->texture->width);
    if ((ray->side == 0 && ray->direction.x < 0) || (ray->side == 1 && ray->direction.y > 0))
        ray->x_on_tex = ray->texture->width - ray->x_on_tex - 1;
    if (ray->x_on_tex < 0)
    	ray->x_on_tex = 0;
    if (ray->x_on_tex >= ray->texture->width)
    	ray->x_on_tex = ray->texture->width - 1;
}

