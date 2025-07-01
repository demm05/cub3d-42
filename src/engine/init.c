/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:14:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/07/01 11:41:07 by ogrativ          ###   ########.fr       */
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
	if (world_init(eng->mlx, &eng->world, map_path) == -1
		|| !camera_set_start_pos(eng))
		return (0);
	if (!init_mlx_and_window(eng))
		return (0);
	if (!allocate_rays(eng))
		return (0);
	eng->window.mlx = eng->mlx;
	hook_inputs(eng);
	return (1);
}

void	hook_inputs(t_engine *eng)
{
	if (DISABLE_AUTOREPEAT_KEY)
		mlx_do_key_autorepeatoff(eng->mlx);
	mlx_loop_hook(eng->mlx, engine_loop, eng);
	mlx_hook(eng->window.win, DestroyNotify,
		NoEventMask, mlx_loop_end, eng->mlx);
	mlx_hook(eng->window.win, KeyPress,
		KeyPressMask, input_keyboard_press, eng);
	mlx_hook(eng->window.win, KeyRelease,
		KeyReleaseMask, input_keyboard_release, eng);
	mlx_hook(eng->window.win, FocusIn,
		FocusChangeMask, input_focus_in, eng);
	mlx_hook(eng->window.win, FocusOut,
		FocusChangeMask, input_focus_out, eng);
}
