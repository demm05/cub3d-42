#include "game_private.h"
#include "mlx.h"

void game_hook(t_cube *cube)
{
    if (!cube)
        return;
    if (ENABLE_RESIZE)
        mlx_enable_window_resize(cube->mlx);
    if (DO_KEY_AUTOREPEAT)
        mlx_do_key_autorepeatoff(cube->mlx->mlx);

    mlx_loop_hook(cube->mlx->mlx, game_loop, cube);
    mlx_hook(cube->mlx->win, 17, 0, mlx_stop_loop, cube->mlx);

    mlx_mouse_hook(cube->mlx->win, game_handle_mouse_press, cube);
    mlx_hook(cube->mlx->win, 6, 1L << 6, game_handle_mouse_move, cube);
    mlx_hook(cube->mlx->win, 2, 1L << 0, game_handle_keyboard_press, cube);
    mlx_hook(cube->mlx->win, 3, 1L << 1, game_handle_keyboard_release, cube);
}
