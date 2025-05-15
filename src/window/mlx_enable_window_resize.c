#include "mlx_int.h"
#include "window_private.h"
#include <X11/X.h>

void	mlx_enable_window_resize(t_mlx_data *mlx)
{
	XSizeHints	hints;
	long		toto;
	t_xvar		*xvar;
	Window		*win;

	xvar = mlx->mlx;
	win = mlx->win;
	XGetWMNormalHints(xvar->display, *win, &hints, &toto);
	hints.width = WIDTH;
	hints.height = HEIGHT;
	hints.min_width = 100;
	hints.min_height = 100;
	hints.max_width = 1920;
	hints.max_height = 1080;
	hints.flags = PPosition | PSize | PMinSize | PMaxSize;
	XSetWMNormalHints(xvar->display, *win, &hints);
}
