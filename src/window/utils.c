#include "window.h"

void mlx_put_pixel(t_mlx_img *img, int x, int y, int color)
{
	int offset;

	offset = (y * img->line_size) + (x * (img->depth / 8));
	*((unsigned int *) (offset + img->buffer)) = color;
}
