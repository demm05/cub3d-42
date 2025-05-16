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
	if (DEBUG)
		printf("press: %d\n", keycode);
	return (0);
}

int	game_handle_keyboard_release(int keycode, t_cube *cube)
{
	(void) cube;
	if (DEBUG)
		printf("release: %d\n", keycode);
	return (0);
}
