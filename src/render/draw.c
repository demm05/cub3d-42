/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:04:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/28 17:04:27 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

MAYBE_INLINE void	draw_vert_line(t_frame_buf *buf, int x, int start, int end,
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

MAYBE_INLINE void	draw_rectangle(t_frame_buf *buf, int x, int y, int width,
						int height, int color)
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;

	x_start = x;
	y_start = y;
	x_end = x + width;
	y_end = y + height;
	if (x_start < 0)
		x_start = 0;
	if (y_start < 0)
		y_start = 0;
	if (x_end > buf->width)
		x_end = buf->width;
	if (y_end > buf->height)
		y_end = buf->height;
	y = y_start;
	while (y < y_end)
	{
		x = x_start;
		while (x < x_end)
		{
			draw_pixel(buf, x++, y, color);
			// draw_pixel(buf, x, y, get_pixel_color(buf, x, y));
			x++;
		}
		y++;
	}
}

MAYBE_INLINE void	draw_pixel(t_frame_buf *buf, int x, int y, int color)
{
	*((unsigned int *)((y * buf->line_size) + \
			(x * (buf->depth / 8)) + buf->buffer)) = color;
}

MAYBE_INLINE void	draw_for_each_pixel(t_image *img, void *param, int x_end, int y_end, int foo(int x, int y, void *param))
{
	char	*pixel_addr; // Using int * improves performance
	int		step;
	int		x;
	int		y;

	step = img->depth / 8;
	y = -1;
	while (++y < y_end)
	{
		x = -1;
		pixel_addr = img->buffer + y * img->line_size;
		while (++x < x_end)
		{
			*(int *)pixel_addr = foo(x, y, param);
			pixel_addr += step;
		}
	}
}

