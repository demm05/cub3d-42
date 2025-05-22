/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:26:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 12:35:22 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"
#include "mlx_int.h"
#include <X11/X.h>


bool	init_mlx_and_window(t_engine *eng)
{
	int	x;
	int	y;

	if (!eng)
		return (0);
	eng->mlx = mlx_init();
	if (!eng->mlx)
		return (0);
	eng->window.win = mlx_new_window(eng->mlx, eng->window.width, eng->window.height, eng->window.title);
	if (!eng->window.win)
		return (0);
	mlx_get_screen_size(eng->mlx, &x, &y);
#if DEBUG
	printf("Screen properties: (width)%d;(height)%d\n", x, y);
#endif
	if (!buffer_create(eng->mlx, &eng->main_buffer, x, y))
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
	hints.max_width = 1920;
	hints.max_height = 1080;
	hints.flags = PPosition | PSize | PMinSize | PMaxSize;
	XSetWMNormalHints(xvar->display, *win, &hints);
}
