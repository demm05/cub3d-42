/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:04:23 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 15:17:07 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"

inline void	buffer_flash(t_frame_buf *buf, t_window *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->win, buf->img, x, y);
}

inline void	buffer_clear(t_frame_buf *buf)
{
	ft_memset(buf->buffer, 0, buf->height * buf->line_size);
}
