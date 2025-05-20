#include "player.h"

MAYBE_INLINE void	update_movements(t_player *player, t_window *win)
{
	double move_amount;

	move_amount = player->speed * win->timing.delta;
	if (player->moving_up && player->y > 0)
		player->y -= move_amount;
	if (player->moving_down && player->y < win->height - PLAYER_2D_SIZE)
		player->y += move_amount;
	if (player->moving_left && player->x > 0)
		player->x -= move_amount;
	if (player->moving_right && player->x < win->width - PLAYER_2D_SIZE)
		player->x += move_amount;

	if (player->y < 0)
		player->y = 0;
	if (player->y > (double)win->height - PLAYER_2D_SIZE)
		player->y = (double)win->height - PLAYER_2D_SIZE;
	if (player->x < 0)
		player->x = 0;
	if (player->x > (double)win->width - PLAYER_2D_SIZE)
		player->x = (double)win->width - PLAYER_2D_SIZE;
}

