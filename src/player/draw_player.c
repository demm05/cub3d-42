#include "player.h"

MAYBE_INLINE void	draw_player(t_window *window, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	while (x < PLAYER_2D_SIZE && player->x + (double)x < (double)window->width)
	{
		y = 0;
		while (y < PLAYER_2D_SIZE && player->y + (double)y < (double)window->height)
		{
			win_pixel_put(window, player->x + x, y + player->y, 0xFFDDFF);
			y++;
		}
		x++;
	}
}
