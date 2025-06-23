/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:16 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:16 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

MAYBE_INLINE void	menu_mouse_press(t_engine *eng, int keycode, int x, int y)
{
	t_mi_prop	*p;
	t_menu		*m;
	int			item;

	(void)keycode;
	eng->draw_new_frame = 1;
	m = &eng->menu;
	item = -1;
	while (++item < m->size)
	{
		p = &m->main[item];
		if (x > p->draw_start.x && x < p->draw_end.x && y > p->draw_start.y && y < p->draw_end.y)
			return (p->caller(eng));
	}
	eng->draw_new_frame = 0;
}
