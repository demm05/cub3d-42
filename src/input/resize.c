#include "input_private.h"
#include "mlx_int.h"

int	input_event_resize(t_engine *eng)
{
	XWindowAttributes	attr;
	Window				*win;
	t_xvar				*xvar;

	xvar = eng->mlx;
	win = eng->window.win;
	XGetWindowAttributes(xvar->display, *win, &attr);
	if (attr.width <= eng->window.max_width)
		eng->window.width = attr.width;
	else
		eng->window.width = eng->window.max_width;
	if (attr.height <= eng->window.height)
		eng->window.height = attr.height;
	else
		eng->window.height = eng->window.max_height;
	return (0);
}

