/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:13 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_mi_prop	*menu_create_stack(t_menu_item items[], int size);

bool	menu_set_items(t_engine *eng)
{
	static t_menu_item	items[] = {
		{"Start Game", menu_switch_state},
		{"Quit", enging_loop_stop}
	};
	eng->menu.size = sizeof(items) / sizeof(items[0]);
	eng->menu.main = menu_create_stack(items, eng->menu.size);
	if (!eng->menu.main)
		return (FAILURE);
	menu_update_properties(eng);
	return (SUCCESS);
}

void	menu_update_properties(t_engine *eng)
{
	t_mi_prop	*p;
	t_menu		*m;
	int			i;
	int			starty;

	m = &eng->menu;
	i = -1;
	m->bs.x = eng->window.width / MENU_BUTTON_WIDTH;
	m->bs.y = eng->window.height / MENU_BUTTON_HEIGHT;
	m->bg = m->bs.y / MENU_BUTTON_PADDING;
	starty = (eng->window.height - m->bs.y) / 2;
	while (++i < m->size)
	{
		p = &m->main[i];
		p->draw_start.x = (eng->window.width - m->bs.x) / 2;
		p->draw_start.y = starty + i * (m->bs.y + m->bg);
		p->draw_end.x = p->draw_start.x + m->bs.x;
		p->draw_end.y = p->draw_start.y + m->bs.y;
	}
}

static t_mi_prop	*menu_create_stack(t_menu_item items[], int size)
{
	t_mi_prop	*res;
	int			i;

	res = malloc(sizeof(*res) * size);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		res[i].caller = items[i].caller;
		res[i].text = items[i].text;
	}
	return (res);
}
