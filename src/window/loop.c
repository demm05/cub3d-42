#include "window_private.h"

void mlx_start_loop(t_cube *cube)
{
	if (!cube)
		return;
	cube->mlx = create_window();
	if (!cube->mlx)
		return;
	hook_events(cube);
	mlx_loop(cube->mlx->mlx);
}

void hook_events(t_cube *cube)
{
	if (!cube)
		return;
	mlx_hook(cube->mlx->win, 17, 0, destroy_event, cube);
}

int destroy_event(t_cube *cube)
{
	mlx_free(cube->mlx);
	exit(EXIT_SUCCESS);
}
