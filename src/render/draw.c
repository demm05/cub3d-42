/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:04:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 11:36:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

inline void	draw_vert_line(t_frame_buf *buf, int x, int start, int end,
						int color)
{
	if (start > end)
		return ;
	if (start < 0)
	{
		end += start;
		start = 0;
	}
	if (end > buf->height)
		end = buf->height;
	while (start < end)
		draw_pixel(buf, x, start++, color);
}

inline void	draw_for_each_pixel(t_engine *eng, t_point end,
				unsigned int foo(t_engine *eng, int x, int y,
					unsigned int color))
{
	unsigned int	*pixel_addr;
	int				x;
	int				y;

	y = -1;
	while (++y < end.y)
	{
		x = -1;
		pixel_addr = (unsigned int *)(eng->main_buffer.buffer + y * \
			eng->main_buffer.line_size);
		while (++x < end.x)
			pixel_addr[x] = foo(eng, x, y, pixel_addr[x]);
	}
}

inline void	draw_from_to_each(t_engine *eng, t_point start, t_point size,
							t_ui foo(t_engine *eng, int x, int y, t_ui color))
{
	unsigned int	*pixel_addr;
	int				x;
	int				y;

	y = -1;
	while (++y < size.y)
	{
		x = -1;
		pixel_addr = (unsigned int *)(eng->main_buffer.buffer + (y + start.y) *
			eng->main_buffer.line_size + (start.x * 4));
		while (++x < size.x)
			pixel_addr[x] = foo(eng, x, y, pixel_addr[x]);
	}
}

