/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:58:57 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 13:13:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "cube.h"

typedef struct s_engine	t_engine;

typedef struct s_input
{
	int		mouse_move;
	char	moving_up;
	char	moving_down;
	bool	moving_left;
	bool	moving_right;
	bool	look_left;
	bool	look_right;
	bool	minimap_toggle;
	bool	resizing;
	t_vec2_int	prev_mouse_pos;
}	t_input;

int		input_keyboard_press(int keycode, t_engine *eng);
int		input_keyboard_release(int keycode, t_engine *eng);
int		input_mouse_press(int key, int x, int y, t_engine *eng);
int		input_mouse_move(int x, int y, t_engine *eng);
int		input_focus_in(t_engine *eng);
int		input_focus_out(t_engine *eng);
void	minimap_toggle(t_engine *eng);

#endif
