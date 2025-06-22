#include "cube.h"

void	set_items(t_engine *eng)
{
	static t_menu_item	items[] = {
		{"Start Game", menu_switch_state},
		{"Quit", enging_loop_stop}
	};
	eng->menu.main = items;
	eng->menu.size = sizeof(items) / sizeof(items[0]);
}
