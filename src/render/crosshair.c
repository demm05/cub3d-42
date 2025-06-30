#include "render_private.h"

MAYBE_INLINE void	render_crosshair(t_engine *eng)
{
	t_point	start;
	int		size;

	size = 3;
	start.x = (eng->window.width - size) >> 1;
	start.y = (eng->window.height - size) >> 1;
	draw_rectangle(eng, start, (t_point){size, size}, 0xfafafa);
}
