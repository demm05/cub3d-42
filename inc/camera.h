/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:59:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/30 15:09:46 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "cube.h"

typedef struct s_camera
{
	t_vec2_double	pos;
	t_vec2_double	dir;
	t_vec2_double	plane;
	double			move_speed;
	double			rotation_speed;
	float			mouse_speed;
}	t_camera;

void	camera_keyboard_move_event(t_engine *eng, t_camera *cam);
void	camera_keyboard_rotate_event(t_engine *eng);
void	camera_mouse_move_event(t_engine *eng);
bool	camera_set_start_pos(t_engine *eng);

#endif
