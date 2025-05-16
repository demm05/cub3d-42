/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:02:42 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/16 13:02:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

void	hook_events(t_cube *cube)
{
	if (!cube)
		return ;
	mlx_mouse_hook(cube->mlx->win, mlx_handle_mouse_press, cube);
	mlx_hook(cube->mlx->win, 17, 0, mlx_stop_loop, cube->mlx);
	mlx_hook(cube->mlx->win, 6, 1L << 6, mlx_handle_mouse_move, cube);
	mlx_hook(cube->mlx->win, 2, 1L << 0, mlx_handle_keyboard_press, cube);
	mlx_hook(cube->mlx->win, 3, 1L << 1, mlx_handle_keyboard_release, cube);
}
