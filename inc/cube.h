#ifndef CUBE_H
#define CUBE_H

#define WIDTH 1280
#define HEIGHT 720
#define WINDOW_NAME "CUB3D"
#define ENABLE_RESIZE 0

#include <stdio.h>
#include <stdlib.h>

#include "libft/include/libft.h"

typedef struct s_mlx_data t_mlx_data;

typedef struct s_window
{
	unsigned int width;
	unsigned int height;
} t_window;

typedef struct s_cube
{
	t_window    window;
	t_mlx_data *mlx;
} t_cube;

#ifndef WINDOW_H
#include "../src/window/window.h"
#endif

#endif
