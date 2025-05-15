#ifndef WINDOW_H
# define WINDOW_H

# include "cube.h"

typedef struct s_mlx_img
{
	void	*img;
	char	*buffer;
	int		depth;
	int		line_size;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_mlx_img	img;
}	t_mlx_data;

void	mlx_put_pixel(t_mlx_img *img, int x, int y, int color);

// This function creates a window and start's a loop
void	mlx_start_loop(t_cube *cube);

// This function stop's the loop of the window and memory of 
// mlx_data is freed automatically
int		mlx_stop_loop(t_mlx_data *mlx);

#endif
