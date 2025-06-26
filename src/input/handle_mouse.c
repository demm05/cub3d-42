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

static void	mouse_move_game(int x, int y, t_engine *eng)
{
	const int	offset = 150;
	t_point		*p;

	p = &eng->input.prev_mouse_pos;
	if (!p->x)
	{
		if (x < offset)
			p->x = offset;
		else if (x > eng->window.width - offset)
			p->x = eng->window.width - offset;
		else
			p->x = x;
		if (y < offset)
			p->y = offset;
		else if (y > eng->window.height - offset)
			p->y = eng->window.height - offset;
		else
			p->y = y;
	}
	if (x - eng->input.prev_mouse_pos.x == 0)
		return ;
	eng->input.mouse_move = eng->input.prev_mouse_pos.x - x;
	x = eng->input.prev_mouse_pos.x;
	mlx_mouse_move(eng->mlx, eng->window.win, x, eng->input.prev_mouse_pos.y);
}

int	input_mouse_press(int key, int x, int y, t_engine *eng)
{
#if DEBUG
	printf("mouse_press: %d %dx%d\n", key, x, y);
#endif
	if (eng->state == MENU)
		menu_mouse_press(eng, key, x, y);
	else
		eng->player.health--;
	return (0);
}

int	input_mouse_move(int x, int y, t_engine *eng)
{
	if (eng->state == PLAYING)
		mouse_move_game(x, y, eng);
	return (0);
}
