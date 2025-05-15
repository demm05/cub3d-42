#include "cube.h"
#include "window_private.h"

void hook_events(t_cube *cube)
{
	if (!cube)
		return;
	mlx_hook(cube->mlx->win, 17, 0, mlx_stop_loop, cube->mlx);
	mlx_key_hook(cube->mlx->win, mlx_handle_keyboard, cube);
	mlx_mouse_hook(cube->mlx->win, mlx_handle_mouse_press, cube);
	mlx_hook(cube->mlx->win, 6, 1L << 6, mlx_handle_mouse_move, cube);
}

void mlx_start_loop(t_cube *cube)
{
	if (!cube)
		return;
	cube->mlx = create_window(&cube->window);
	if (!cube->mlx)
		return;
	hook_events(cube);
	if (ENABLE_RESIZE)
		mlx_enable_window_resize(cube->mlx);
	mlx_loop(cube->mlx->mlx);
	mlx_free(&cube->mlx);
}

int mlx_stop_loop(t_mlx_data *mlx)
{
	mlx_loop_end(mlx->mlx);
	return (0);
}
