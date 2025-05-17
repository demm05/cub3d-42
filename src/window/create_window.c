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
	{
		ft_fprintf(2, "error: create_window: mlx_new_window\n");
		return (0);
	}
	win->img = mlx_new_image(mlx, win->width, win->height);
	if (!win->img)
	{
		ft_fprintf(2, "error: create_window: mlx_new_image\n");
		return (0);
	}
	win->buffer = mlx_get_data_addr(win->img, &win->depth, &win->line_size,
			&win->endian);
	if (!win->buffer)
	{
		ft_fprintf(2, "error: create_window: mlx_get_data_addr\n");
		return (0);
	}
	return (1);
}
