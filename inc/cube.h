#ifndef CUBE_H
#define CUBE_H

#define WIDTH 1000
#define HEIGHT 1000
#define WINDOW_NAME "CUB3D"

#include <stdio.h>
#include <stdlib.h>

#include "libft/include/libft.h"

typedef struct s_mlx_data t_mlx_data;

typedef struct s_cube
{
	t_mlx_data *mlx;
} t_cube;

#ifndef WINDOW_H
#include "../src/window/window.h"
#endif

#endif
