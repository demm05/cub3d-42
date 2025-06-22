#include "cube.h"

void	menu_switch_state(t_engine *eng)
{
	if (!eng)
		return ;
#if DEBUG
	printf("Switching from state %d\n", eng->state);
#endif
	if (eng->state == MENU)
	{
		ft_bzero(&eng->input.prev_mouse_pos, sizeof(t_point));
		eng->state = PLAYING;
		mlx_mouse_hide(eng->mlx, eng->window.win);
	}
	else
	{
		eng->state = MENU;
		mlx_mouse_show(eng->mlx, eng->window.win);
	}
}
