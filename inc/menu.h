#ifndef MENU_H
# define MENU_H

# include "cube.h"

typedef enum e_state
{
	PLAYING,
	MENU
}	t_state;

void	menu_switch_state(t_engine *eng);

#endif
