#include "window_private.h"

void mlx_free(t_mlx_data *data)
{
	if (!data)
		return;
	if (data->mlx)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->img.img)
			mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

t_mlx_data *create_window(void)
{
	t_mlx_data *data;

	data = ft_calloc(1, sizeof(t_mlx_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (NULL);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	if (!data->win)
	{
		mlx_free(data);
		return (NULL);
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
	{
		mlx_free(data);
		return (NULL);
	}
	data->img.buffer = mlx_get_data_addr(data->img.img, &data->img.depth,
	                                     &data->img.line_size, &data->img.endian);
	return (data);
}
