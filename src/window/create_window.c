/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:15:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/16 16:15:51 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

bool	create_window(void *mlx, t_window *win)
{
	win->win = mlx_new_window(mlx, win->width, win->height, WINDOW_NAME);
	if (!win->win)
		return (0);
	win->img = mlx_new_image(mlx, win->width, win->height);
	if (!win->img)
		return (0);
	win->buffer = mlx_get_data_addr(win->img, &win->depth, &win->line_size,
			&win->endian);
	if (!win->buffer)
		return (0);
	win->frame_zero_time = get_current_time();
	return (1);
}
