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
	cube->mlx = mlx_init();
	if (!cube->mlx)
		return ;
	if (!create_window(cube->mlx, &cube->window))
	{
		mlx_free(cube);
		return ;
	}
	cube->window.mlx = cube->mlx;
	if (DISABLE_AUTOREPEAT_KEY)
		mlx_do_key_autorepeatoff(cube->mlx);
	game_hook(cube);
	mlx_loop(cube->mlx);
	mlx_free(cube);
}

int	mlx_stop_loop(void *mlx)
{
	if (DEBUG)
		printf("mlx_stop_loop is called\n");
	if (DISABLE_AUTOREPEAT_KEY)
		mlx_do_key_autorepeaton(mlx);
	mlx_loop_end(mlx);
	return (0);
}
