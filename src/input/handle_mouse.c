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
	static t_vec2_int	prev;

#if DEBUG
	printf("mouse_move: %dx%d\n", x, y);
#endif
	y = eng->window.height / 2;
	if (!prev.x && !prev.y)
	{
		x = eng->window.width / 2;
		prev.x = x;
		prev.y = y;
		mlx_mouse_move(eng->mlx, eng->window.win, x, y);
	}
	if (x - prev.x == 0)
		return (0);
	eng->input.mouse_move = prev.x - x;
	x = prev.x;
	mlx_mouse_move(eng->mlx, eng->window.win, x, y);
	return (0);
}
