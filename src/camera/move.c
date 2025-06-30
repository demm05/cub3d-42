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

static inline void	set_new(t_input *input, t_vec2_double *new, t_vec2_double dir)
{
	if (input->moving_up)
	{
		new->x += dir.x;
		new->y += dir.y;
	}
	if (input->moving_down)
	{
		new->x -= dir.x;
		new->y -= dir.y;
	}
	if (input->moving_left)
	{
		new->x += dir.y;
		new->y -= dir.x;
	}
	if (input->moving_right)
	{
		new->x -= dir.y;
		new->y += dir.x;
	}
}

MAYBE_INLINE void	camera_keyboard_move_event(t_engine *eng, t_camera *cam)
{
	double			move_amount;
	t_vec2_double	new;

	move_amount = eng->player.move_speed * eng->timing.delta_time;
	if ((eng->input.moving_left || eng->input.moving_right) &&
		(eng->input.moving_up || eng->input.moving_down))
		move_amount *= 0.8;
	new.x = cam->pos.x;
	new.y = cam->pos.y;
	set_new(&eng->input, &new, (t_vec2_double){cam->dir.x * move_amount,
		cam->dir.y * move_amount});
	move_camera(cam, eng->map, new.x, new.y);
}
