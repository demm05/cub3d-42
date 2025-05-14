#ifndef WINDOW_H
#define WINDOW_H

#include "cube.h"

typedef struct s_mlx_img
{
	void *img;
	char *buffer;
	int   depth;
	int   line_size;
	int   endian;
} t_mlx_img;

typedef struct s_mlx_data
{
	void     *mlx;
	void     *win;
	t_mlx_img img;
} t_mlx_data;

void mlx_put_pixel(t_mlx_img *img, int x, int y, int color);
void mlx_start_loop(t_cube *cube);

#endif
