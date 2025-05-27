#include "render_private.h"
#include <string.h>

MAYBE_INLINE void	buffer_flash(t_frame_buf *buf, t_window *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->win, buf->img, x, y);
}

MAYBE_INLINE void	buffer_clear(t_frame_buf *buf)
{
	memset(buf->buffer, 0, buf->height * buf->line_size);
}
