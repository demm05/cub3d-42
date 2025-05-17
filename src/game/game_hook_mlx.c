/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:15:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/16 16:15:55 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_private.h"
#include "mlx.h"

void	game_hook(t_cube *cube)
{
	if (!cube)
		return ;
	if (ENABLE_RESIZE)
		mlx_enable_window_resize(cube->mlx, &cube->window);
	mlx_loop_hook(cube->mlx, game_loop, cube);
	mlx_hook(cube->window.win, 17, 0, mlx_stop_loop, cube->mlx);
	mlx_mouse_hook(cube->window.win, game_handle_mouse_press, cube);
	mlx_hook(cube->window.win, 6, 1L << 6, game_handle_mouse_move, cube);
	mlx_hook(cube->window.win, 2, 1L << 0, game_handle_keyboard_press, cube);
	mlx_hook(cube->window.win, 3, 1L << 1, game_handle_keyboard_release, cube);
}
