/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:20:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 13:09:46 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_private.h"
#include <X11/keysym.h>

int	input_keyboard_press(int keycode, t_engine *eng)
{
#if DEBUG
	printf("press: %d\tup: %d\tdown: %d\n", keycode, eng->input.moving_up, eng->input.moving_down);
#endif
	if (keycode == XK_w || keycode == XK_Up)
		eng->input.moving_up++;
	else if (keycode == XK_a)
		eng->input.moving_left = 1;
	else if (keycode == XK_s || keycode == XK_Down)
		eng->input.moving_down++;
	else if (keycode == XK_d)
		eng->input.moving_right = 1;
	else if (keycode == XK_Left)
		eng->input.look_left= 1;
	else if (keycode == XK_Right)
		eng->input.look_right = 1;
	else if (keycode == XK_Shift_L)
		eng->camera.move_speed *= 1.5;
	else if (keycode == XK_m)
		eng->input.minimap_toggle = !eng->input.minimap_toggle;
	return (0);
}

int	input_keyboard_release(int keycode, t_engine *eng)
{
#if DEBUG
	printf("release: %d\tup: %d\tdown: %d\n", keycode, eng->input.moving_up, eng->input.moving_down);
#endif
	if (keycode == XK_Escape)
		mlx_loop_end(eng->mlx);
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
	return (0);
}
