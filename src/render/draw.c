#include "render_private.h"

MAYBE_INLINE void	draw_vert_line(t_frame_buf *buf, int x, int start, int end, int color)
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
	// printf("%d %d %d\n", x, start, end);
	while (start < end)
		draw_pixel(buf, x, start++, color);
}

MAYBE_INLINE void	draw_rectangle(t_frame_buf *buf, int x, int y, int width, int height, int color)
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
			draw_pixel(buf, x++, y, color);
		y++;
	}
}

MAYBE_INLINE void	draw_pixel(t_frame_buf *buf, int x, int y, int color)
{
	*((unsigned int *)((y * buf->line_size) + (x * (buf->depth / 8)) + buf->buffer)) = color;
}
