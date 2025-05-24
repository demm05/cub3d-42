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
	printf("press: %d\n", keycode);
#endif
	if (keycode == XK_w)
		eng->input.moving_up = 1;
	else if (keycode == XK_a)
		eng->input.moving_left = 1;
	else if (keycode == XK_s)
		eng->input.moving_down = 1;
	else if (keycode == XK_d)
		eng->input.moving_right = 1;
	return (0);
}

int	input_keyboard_release(int keycode, t_engine *eng)
{
#if DEBUG
	printf("release: %d\n", keycode);
#endif
	if (keycode == XK_Escape)
		mlx_loop_end(eng->mlx);
	else if (keycode == XK_w)
		eng->input.moving_up = 0;
	else if (keycode == XK_a)
		eng->input.moving_left = 0;
	else if (keycode == XK_s)
		eng->input.moving_down = 0;
	else if (keycode == XK_d)
		eng->input.moving_right = 0;
	return (0);
}
