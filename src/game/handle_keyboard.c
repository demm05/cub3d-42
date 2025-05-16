/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:15:44 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/16 16:15:57 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_private.h"
#include <X11/keysym.h>

static inline int	general_movement(int keycode, t_cube *cube)
{
	if (keycode == XK_w)
		cube->player.moving_up = !cube->player.moving_up;
	else if (keycode == XK_a)
		cube->player.moving_left = !cube->player.moving_left;
	else if (keycode == XK_s)
		cube->player.moving_down = !cube->player.moving_down;
	else if (keycode == XK_d)
		cube->player.moving_right = !cube->player.moving_right ;
	else
		return (0);
	return (1);
}

int	game_handle_keyboard_press(int keycode, t_cube *cube)
{
	(void) cube;
	if (DEBUG)
		printf("press: %d\n", keycode);
	if (general_movement(keycode, cube))
	{
	}
	return (0);
}

int	game_handle_keyboard_release(int keycode, t_cube *cube)
{
	(void) cube;
	if (DEBUG)
		printf("release: %d\n", keycode);
	if (general_movement(keycode, cube))
	{
	}
	return (0);
}
