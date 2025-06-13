/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:37:40 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/10 14:18:24 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"
#include <math.h>

static inline void	rotate(t_camera *cam, double move_amount)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cam->dir.x;
	cam->dir.x = cam->dir.x * cos(move_amount) - cam->dir.y * sin(move_amount);
	cam->dir.y = old_dir_x * sin(move_amount) + cam->dir.y * cos(move_amount);
	old_plane_x = cam->plane.x;
	cam->plane.x = cam->plane.x * cos(move_amount) - cam->plane.y * sin(move_amount);
	cam->plane.y = old_plane_x * sin(move_amount) + cam->plane.y * cos(move_amount);
}

MAYBE_INLINE void	camera_keyboard_rotate_event(t_engine *eng)
{
	double	move_amount;

	move_amount = eng->camera.rotation_speed * eng->timing.delta_time;
	if (eng->input.look_left)
		rotate(&eng->camera, -move_amount);
	if (eng->input.look_right)
		rotate(&eng->camera, move_amount);
}

MAYBE_INLINE void	camera_mouse_move_event(t_engine *eng)
{
	double	move_amount;

	if (!eng->input.mouse_move)
		return ;
	move_amount = eng->camera.mouse_speed * eng->timing.delta_time * eng->input.mouse_move;
	rotate(&eng->camera, -move_amount);
	eng->input.mouse_move = 0;
}
