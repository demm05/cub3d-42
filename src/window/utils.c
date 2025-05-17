/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "window_private.h"
#include <string.h>

MAYBE_INLINE void	win_pixel_put(t_window *win, int x, int y, int color)
{
#ifdef ENABLE_MLX_PUT
	mlx_pixel_put(win->mlx, win->win, x, y, color);
#else
	*((unsigned int *)((y * win->line_size) + (x * (win->depth / 8)) \
		+ win->buffer)) = color;
#endif
}

MAYBE_INLINE void	win_clear_buffer(void *mlx, t_window *win)
{
#ifdef ENABLE_MLX_PUT
	mlx_clear_window(mlx, win->win);
#else
	memset(win->buffer, 0, win->height * win->line_size);
#endif
}

MAYBE_INLINE void	win_flash_buffer(void *mlx, t_window *win)
{
#ifdef ENABLE_MLX_PUT
	mlx_do_sync(mlx);
#else
	mlx_put_image_to_window(mlx, win->win, win->img, 0, 0);
#endif
}
