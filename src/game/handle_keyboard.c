#include "game_private.h"
#include <X11/keysym.h>

int	game_handle_keyboard_press(int keycode, t_cube *cube)
{
	(void) cube;
	if (DEBUG)
		printf("press: %d\n", keycode);
	return (0);
}

int	game_handle_keyboard_release(int keycode, t_cube *cube)
{
	(void) cube;
	if (DEBUG)
		printf("release: %d\n", keycode);
	return (0);
}
