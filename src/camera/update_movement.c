/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/28 17:05:26 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"
#include <math.h>

// This is not good because player becomes a square
static inline void	move_camera(t_camera *cam, t_world *world, double new_x, double new_y)
{
	const double	padding = 0.1;

	if (map_get(world, new_x - padding, cam->pos.y - padding) <= '0' && \
		map_get(world, new_x + padding, cam->pos.y - padding) <= '0' && \
		map_get(world, new_x - padding, cam->pos.y + padding) <= '0' && \
		map_get(world, new_x + padding, cam->pos.y + padding) <= '0')
		cam->pos.x = new_x;
	if (map_get(world, cam->pos.x - padding, new_y - padding) <= '0' && \
		map_get(world, cam->pos.x - padding, new_y + padding) <= '0' && \
		map_get(world, cam->pos.x + padding, new_y - padding) <= '0' && \
		map_get(world, cam->pos.x + padding, new_y  + padding) <= '0')
		cam->pos.y = new_y;
}

MAYBE_INLINE void	update_keyboard_events(t_camera *cam, t_input *inp, t_timing *tm, t_world *world)
{
	double	move_amount;
	double	dir_x;
	double	dir_y;

	move_amount = cam->move_speed * tm->delta_time;
	dir_x = cam->dir.x * move_amount;
	dir_y = cam->dir.y * move_amount;
	if (inp->moving_up)
		move_camera(cam, world, cam->pos.x + dir_x, cam->pos.y + dir_y);
	if (inp->moving_down)
		move_camera(cam, world, cam->pos.x - dir_x, cam->pos.y - dir_y);
	if (inp->moving_left)
		move_camera(cam, world, cam->pos.x - dir_y, cam->pos.y + dir_x);
	if (inp->moving_right)
		move_camera(cam, world, cam->pos.x + dir_y, cam->pos.y - dir_x);
}

MAYBE_INLINE void	update_mouse_event(t_camera *cam, t_input *inp, t_timing *tm)
{
	double	move_amount;
	double	old_dir_x;
	double	old_plane_x;

	move_amount = cam->rotation_speed * tm->delta_time;
	if (inp->look_left)
	{
		old_dir_x = cam->dir.x;
		cam->dir.x = cam->dir.x * cos(move_amount) - cam->dir.y * sin(move_amount);
		cam->dir.y = old_dir_x * sin(move_amount) + cam->dir.y * cos(move_amount);
		old_plane_x = cam->plane.x;
		cam->plane.x = cam->plane.x * cos(move_amount) - cam->plane.y * sin(move_amount);
		cam->plane.y = old_plane_x * sin(move_amount) + cam->plane.y * cos(move_amount);
	}
	if (inp->look_right)
	{
		old_dir_x = cam->dir.x;
		cam->dir.x = cam->dir.x * cos(-move_amount) - cam->dir.y * sin(-move_amount);
		cam->dir.y = old_dir_x * sin(-move_amount) + cam->dir.y * cos(-move_amount);
		old_plane_x = cam->plane.x;
		cam->plane.x = cam->plane.x * cos(-move_amount) - cam->plane.y * sin(-move_amount);
		cam->plane.y = old_plane_x * sin(-move_amount) + cam->plane.y * cos(-move_amount);

	}
}
