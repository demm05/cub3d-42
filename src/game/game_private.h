#ifndef GAME_PRIVATE_H
# define GAME_PRIVATE_H

# include "game.h"

int game_handle_keyboard_press(int keycode, t_cube *cube);
int	game_handle_keyboard_release(int keycode, t_cube *cube);
int	game_handle_mouse_press(int key, int x, int y, t_cube *cube);
int	game_handle_mouse_move(int x, int y, t_cube *cube);

#endif
