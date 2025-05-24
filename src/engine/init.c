/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:14:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 12:55:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include "mlx_int.h"

void	hook_inputs(t_engine *eng);

bool	engine_init(t_engine *eng)
{
	if (!eng)
		return (0);
	ft_bzero(eng, sizeof(t_engine));
	set_defaults(eng);
	if (!init_mlx_and_window(eng))
		return (0);
	eng->window.mlx = eng->mlx;
	hook_inputs(eng);
	return (1);
}

void	hook_inputs(t_engine *eng)
{
	if (ENABLE_RESIZE)
		mlx_enable_window_resize(eng->mlx, &eng->window);
	if (DISABLE_AUTOREPEAT_KEY)
		mlx_do_key_autorepeatoff(eng->mlx);
	mlx_loop_hook(eng->mlx, engine_loop, eng);
	mlx_hook(eng->window.win, 17, 0, mlx_loop_end, eng->mlx);
	mlx_mouse_hook(eng->window.win, input_handle_mouse_press, eng);
	mlx_hook(eng->window.win, 6, 1L << 6, input_handle_mouse_move, eng);
	mlx_hook(eng->window.win, 2, 1L << 0, input_keyboard_press, eng);
	mlx_hook(eng->window.win, 3, 1L << 1, input_keyboard_release, eng);
	mlx_hook(eng->window.win, ConfigureNotify, StructureNotifyMask, input_event_resize, eng);
}
