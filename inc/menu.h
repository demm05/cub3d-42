/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:58 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:30:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# define MENU_BUTTON_WIDTH 4
# define MENU_BUTTON_HEIGHT 12
# define MENU_BUTTON_PADDING 2
# define MENU_TEXT_COLOR 0xA0E0E0
# define MENU_BUTTON_COLOR 0xBE1A2A4C
# define MENU_DIM 100

# include "types.h"

typedef enum e_state
{
	PLAYING,
	MENU
}	t_state;

typedef struct s_menu_item_property
{
	char	*text;
	void	(*caller)(t_engine *eng);
	t_point	draw_start;
	t_point	draw_end;
}	t_mi_prop;

typedef struct s_menu_item
{
	char	*text;
	void	(*caller)(t_engine *eng);
}	t_menu_item;

typedef struct s_menu
{
	t_mi_prop	*main;
	int			size;
	t_point		bs;
	int			bg;
}	t_menu;

void	render_menu(t_engine *eng);
void	menu_switch_state(t_engine *eng);
bool	menu_set_items(t_engine *eng);
void	menu_update_properties(t_engine *eng);
void	menu_mouse_press(t_engine *eng, int keycode, int x, int y);

#endif
