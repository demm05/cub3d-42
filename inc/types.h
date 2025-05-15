#ifndef TYPES_H
# define TYPES_H

typedef struct s_mlx_data	t_mlx_data;

typedef struct s_window
{
	unsigned int	width;
	unsigned int	height;
}	t_window;

typedef struct s_cube
{
	t_window	window;
	t_mlx_data	*mlx;
}	t_cube;

#endif
