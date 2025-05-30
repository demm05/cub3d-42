/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:59:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/24 14:22:53 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "cube.h"

typedef struct s_vec2_double
{
	double	x;
	double	y;
}	t_vec2_double;

typedef struct s_vec2_int
{
	int	x;
	int	y;
}	t_vec2_int;

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

#endif
