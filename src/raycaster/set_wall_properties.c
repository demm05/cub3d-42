/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_properties.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:46 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 17:21:16 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_private.h"
#include <math.h>

MAYBE_INLINE void	ray_set_wall_prop(t_engine *eng, t_ray *ray)
{
	// --- 1. Визначаємо точку попадання променя у стіну/двері
	if (ray->side == 0)
		ray->wall_hit = eng->camera.pos.y + ray->wall_dist * ray->direction.y;
	else
		ray->wall_hit = eng->camera.pos.x + ray->wall_dist * ray->direction.x;
	ray->wall_hit -= floor(ray->wall_hit);

	// --- 2. Якщо це двері — малюємо текстуру відповідного кадру
	if (ray->is_door && ray->door_ptr)
	{
		t_door *door = ray->door_ptr;
		int total_frames = eng->textures.door.len;
		int frame = (int)(door->animation * (total_frames - 1));

		// Гарантуємо коректний індекс
		if (frame < 0)
			frame = 0;
		if (frame >= total_frames)
			frame = total_frames - 1;

		ray->texture = &eng->textures.door.img_arr[frame];
	}
	else
		ray->texture = sprite_get_img(&eng->textures.walls, map_get(eng->map, ray->map.x, ray->map.y) - 1);

	// --- 4. Обчислюємо x-координату на текстурі
	ray->x_on_tex = (int)(ray->wall_hit * ray->texture->width);

	if ((ray->side == 0 && ray->direction.x < 0)
		|| (ray->side == 1 && ray->direction.y > 0))
		ray->x_on_tex = ray->texture->width - ray->x_on_tex - 1;

	// --- 5. Безпека для виходу за межі
	if (ray->x_on_tex < 0)
		ray->x_on_tex = 0;
	if (ray->x_on_tex >= ray->texture->width)
		ray->x_on_tex = ray->texture->width - 1;
}