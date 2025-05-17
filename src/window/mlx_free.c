/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

static inline void	for_each_window(void *mlx, t_window *win)
{
	if (win->win)
		mlx_destroy_window(mlx, win->win);
	if (win->img)
		mlx_destroy_image(mlx, win->img);
}

void	mlx_free(t_cube *cube)
{
	if (!cube || !cube->mlx)
		return ;
	for_each_window(cube->mlx, &cube->window);
	mlx_destroy_display(cube->mlx);
	free(cube->mlx);
}
