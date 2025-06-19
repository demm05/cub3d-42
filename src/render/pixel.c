#include "render_private.h"

MAYBE_INLINE t_ui	*get_pixel_address(t_image *img, int x, int y)
{
	return ((t_ui *)(img->buffer + (y * img->line_size) + (x * img->depth8)));
}

MAYBE_INLINE int	get_pixel_color(t_image *img, int x, int y)
{
	return (*get_pixel_address(img, x, y));
}

MAYBE_INLINE void	draw_pixel(t_frame_buf *buf, int x, int y, int color)
{
	*get_pixel_address(buf, x, y) = color;
}
