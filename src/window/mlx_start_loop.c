/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:29 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

void	mlx_start_loop(t_cube *cube)
{
	if (!cube)
		return ;
	cube->mlx = create_window(&cube->window);
	if (!cube->mlx)
		return ;
	game_hook(cube);
	mlx_loop(cube->mlx->mlx);
	mlx_free(&cube->mlx);
}

int	mlx_stop_loop(t_mlx_data *mlx)
{
	if (DEBUG)
		printf("mlx_stop_loop is called\n");
	if (DO_KEY_AUTOREPEAT)
		mlx_do_key_autorepeaton(mlx->mlx);
	mlx_loop_end(mlx->mlx);
	return (0);
}
