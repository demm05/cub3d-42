/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:37:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/10 14:19:01 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"

// This is not good because player becomes a square
static inline void	move_camera(t_camera *cam, t_map *map,
	double new_x, double new_y)
{
	const double	padding = 0.1;

	if (map_get(map, new_x - padding, cam->pos.y - padding) <= 0 && \
		map_get(map, new_x + padding, cam->pos.y - padding) <= 0 && \
		map_get(map, new_x - padding, cam->pos.y + padding) <= 0 && \
		map_get(map, new_x + padding, cam->pos.y + padding) <= 0)
		cam->pos.x = new_x;
	if (map_get(map, cam->pos.x - padding, new_y - padding) <= 0 && \
		map_get(map, cam->pos.x - padding, new_y + padding) <= 0 && \
		map_get(map, cam->pos.x + padding, new_y - padding) <= 0 && \
		map_get(map, cam->pos.x + padding, new_y + padding) <= 0)
		cam->pos.y = new_y;
}

MAYBE_INLINE void	camera_keyboard_move_event(t_engine *eng, t_camera *cam)
{
	double	move_amount;
	double	dir_x;
	double	dir_y;

	move_amount = cam->move_speed * eng->timing.delta_time;
	dir_x = cam->dir.x * move_amount;
	dir_y = cam->dir.y * move_amount;
	if (eng->input.moving_up)
		move_camera(cam, eng->map, cam->pos.x + dir_x, cam->pos.y + dir_y);
	if (eng->input.moving_down)
		move_camera(cam, eng->map, cam->pos.x - dir_x, cam->pos.y - dir_y);
	if (eng->input.moving_left)
		move_camera(cam, eng->map, cam->pos.x + dir_y, cam->pos.y - dir_x);
	if (eng->input.moving_right)
		move_camera(cam, eng->map, cam->pos.x - dir_y, cam->pos.y + dir_x);
}

