#include "window_private.h"

t_mlx_data	*create_window(t_window *win)
{
	t_mlx_data	*data;

	data = ft_calloc(1, sizeof(t_mlx_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (NULL);
	data->win = mlx_new_window(data->mlx, win->width, win->height, WINDOW_NAME);
	if (!data->win)
	{
		mlx_free(&data);
		return (NULL);
	}
	data->img.img = mlx_new_image(data->mlx, win->width, win->height);
	if (!data->img.img)
	{
		mlx_free(&data);
		return (NULL);
	}
	data->img.buffer = mlx_get_data_addr(data->img.img, &data->img.depth,
			&data->img.line_size, &data->img.endian);
	return (data);
}
