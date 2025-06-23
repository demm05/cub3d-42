/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:19 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	render_menu(t_engine *eng)
{
	t_menu	*m;
	int		i;

	m = &eng->menu;
	eng->draw_new_frame = 0;
	text_set_font_size(eng, m->bs.y * 0.6, 0);
	i = -1;
	while (++i < m->size)
	{
		render_rectangle_blend(eng, m->main[i].draw_start, m->bs, MENU_BUTTON_COLOR);
		text_put_str(eng, m->main[i].draw_start, m->main[i].text, MENU_TEXT_COLOR);
	}
}
