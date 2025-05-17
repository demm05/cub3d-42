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

int	game_handle_keyboard_press(int keycode, t_cube *cube)
{
	(void) cube;
#if DEBUG
	printf("press: %d\n", keycode);
#endif
	if (keycode == XK_w)
		cube->player.moving_up = 1;
	else if (keycode == XK_a)
		cube->player.moving_left = 1;
	else if (keycode == XK_s)
		cube->player.moving_down = 1;
	else if (keycode == XK_d)
		cube->player.moving_right = 1;
	return (0);
}

int	game_handle_keyboard_release(int keycode, t_cube *cube)
{
	(void) cube;
#if DEBUG
	printf("release: %d\n", keycode);
#endif
	if (keycode == XK_w)
		cube->player.moving_up = 0;
	else if (keycode == XK_a)
		cube->player.moving_left = 0;
	else if (keycode == XK_s)
		cube->player.moving_down = 0;
	else if (keycode == XK_d)
		cube->player.moving_right = 0;
	return (0);
}
