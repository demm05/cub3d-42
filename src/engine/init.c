/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:14:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/16 12:18:02 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"
#include <X11/X.h>

void	hook_inputs(t_engine *eng);

bool	engine_init(t_engine *eng, char *map_path)
{
	if (!eng)
		return (0);
	ft_bzero(eng, sizeof(t_engine));
	set_defaults(eng);
	eng->mlx = mlx_init();
	if (!eng->mlx)
		return (0);
	if (!parse_file(eng->mlx, &eng->textures, &eng->map, map_path))
		return (0);
	if (!init_mlx_and_window(eng) || !allocate_rays(eng) || \
		!camera_set_start_pos(eng) || !minimap_create(eng) || \
		!update_lookup_table(eng) || !text_init(eng))
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
	mlx_mouse_hook(eng->window.win, input_mouse_press, eng);
	mlx_hook(eng->window.win, DestroyNotify, NoEventMask, mlx_loop_end, eng->mlx);
	mlx_hook(eng->window.win, MotionNotify, PointerMotionMask, input_mouse_move, eng);
	mlx_hook(eng->window.win, KeyPress, KeyPressMask, input_keyboard_press, eng);
	mlx_hook(eng->window.win, KeyRelease, KeyReleaseMask, input_keyboard_release, eng);
	mlx_hook(eng->window.win, ConfigureNotify, StructureNotifyMask, input_event_resize, eng);
	mlx_hook(eng->window.win, FocusIn, FocusChangeMask, input_focus_in, eng);
	mlx_hook(eng->window.win, FocusOut, FocusChangeMask, input_focus_out, eng);
}
