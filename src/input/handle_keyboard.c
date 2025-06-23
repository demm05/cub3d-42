/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:20:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 17:27:01 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_private.h"
#include <X11/keysym.h>

MAYBE_INLINE void	keyboard_press_game(int keycode, t_engine *eng)
{
	if (keycode == XK_w || keycode == XK_Up)
		eng->input.moving_up++;
	else if (keycode == XK_a)
		eng->input.moving_left = 1;
	else if (keycode == XK_s || keycode == XK_Down)
		eng->input.moving_down++;
	else if (keycode == XK_d)
		eng->input.moving_right = 1;
	else if (keycode == XK_Left)
		eng->input.look_left = 1;
	else if (keycode == XK_Right)
		eng->input.look_right = 1;
	else if (keycode == XK_Shift_L)
		eng->camera.move_speed *= 1.5;
	else if (keycode == XK_m)
		minimap_toggle(eng);
	else if (keycode == XK_e)
		eng->input.opening_door = 1;
}

MAYBE_INLINE void	keyboard_release_game(int keycode, t_engine *eng)
{
	if ((keycode == XK_w || keycode == XK_Up) && eng->input.moving_up > 0)
		eng->input.moving_up--;
	else if ((keycode == XK_s || keycode == XK_Down) && eng->input.moving_down > 0)
		eng->input.moving_down--;
	else if (keycode == XK_a)
		eng->input.moving_left = 0;
	else if (keycode == XK_d)
		eng->input.moving_right = 0;
	else if (keycode == XK_Left)
		eng->input.look_left = 0;
	else if (keycode == XK_Right)
		eng->input.look_right = 0;
	else if (keycode == XK_Shift_L)
		eng->camera.move_speed /= 1.5;
}

int	input_keyboard_press(int keycode, t_engine *eng)
{
#if DEBUG
	printf("press: %d\tup: %d\tdown: %d\n", keycode, eng->input.moving_up, eng->input.moving_down);
#endif
	if (eng->state == MENU)
		;
	else if (eng->state == PLAYING)
		keyboard_press_game(keycode, eng);
	return (0);
}

int	input_keyboard_release(int keycode, t_engine *eng)
{
#if DEBUG
	printf("release: %d\tup: %d\tdown: %d\n", keycode, eng->input.moving_up, eng->input.moving_down);
#endif
	if (keycode == XK_Escape)
		menu_switch_state(eng);
	else if (eng->state == MENU)
		;
	else if (eng->state == PLAYING)
		keyboard_release_game(keycode, eng);
	return (0);
}
