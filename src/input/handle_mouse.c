/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:28:35 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 12:29:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_private.h"

int	input_mouse_press(int key, int x, int y, t_engine *eng)
{
	(void) eng;
	(void) key;
	(void) x;
	(void) y;
	return (0);
}

// TODO: if in menu this function should return 0
// TODO: if there was a change of focus we should do nothing
int	input_mouse_move(int x, int y, t_engine *eng)
{
#if DEBUG
	printf("mouse_move: %dx%d\n", x, y);
#endif
	(void)y;
	if (x - eng->input.prev_mouse_pos.x == 0)
		return (0);
	eng->input.mouse_move = eng->input.prev_mouse_pos.x - x;
	x = eng->input.prev_mouse_pos.x;
	mlx_mouse_move(eng->mlx, eng->window.win, x, eng->input.prev_mouse_pos.y);
	return (0);
}
