/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enable_window_resize.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "window_private.h"
#include <X11/X.h>

void	mlx_enable_window_resize(void *mlx, t_window *window)
{
	XSizeHints	hints;
	long		toto;
	t_xvar		*xvar;
	Window		*win;

	xvar = mlx;
	win = window->win;
	XGetWMNormalHints(xvar->display, *win, &hints, &toto);
	hints.width = WIDTH;
	hints.height = HEIGHT;
	hints.min_width = 100;
	hints.min_height = 100;
	hints.max_width = 1920;
	hints.max_height = 1080;
	hints.flags = PPosition | PSize | PMinSize | PMaxSize;
	XSetWMNormalHints(xvar->display, *win, &hints);
}
