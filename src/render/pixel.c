#include "render_private.h"

MAYBE_INLINE int	get_pixel_color(t_image *img, int x, int y)
{
	char	*pixel_addr;
	int		color;

	pixel_addr = img->buffer + (y * img->line_size) + (x * (img->depth / 8));
	color = *(int *)pixel_addr;
	return (color);
}


MAYBE_INLINE void	draw_pixel(t_frame_buf *buf, int x, int y, int color)
{
	*((unsigned int *)((y * buf->line_size) + \
			(x * (buf->depth / 8)) + buf->buffer)) = color;
}
