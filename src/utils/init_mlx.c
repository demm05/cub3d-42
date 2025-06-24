/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:26:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/24 11:17:26 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"
#include "mlx_int.h"
#include <X11/X.h>

bool	init_mlx_and_window(t_engine *eng)
{
	if (!eng)
		return (0);
	eng->window.win = mlx_new_window(eng->mlx, eng->window.width,
			eng->window.height, eng->window.title);
	if (!eng->window.win)
		return (0);
	mlx_get_screen_size(eng->mlx, &eng->window.max_width,
		&eng->window.max_height);
	if (!buffer_create(eng->mlx, &eng->main_buffer, eng->window.max_width, eng->window.max_height))
		return (0);
	return (1);
}

void	mlx_enable_window_resize(void *mlx, t_window *window)
{
	XSizeHints	hints;
	long		toto;
	t_xvar		*xvar;
	Window		*win;

	xvar = mlx;
	win = window->win;
	XGetWMNormalHints(xvar->display, *win, &hints, &toto);
	hints.width = window->width;
	hints.height = window->height;
	hints.min_width = 100;
	hints.min_height = 100;
	hints.max_width = window->max_width;
	hints.max_height = window->max_height;
	hints.flags = PPosition | PSize | PMinSize | PMaxSize;
	XSetWMNormalHints(xvar->display, *win, &hints);
}
