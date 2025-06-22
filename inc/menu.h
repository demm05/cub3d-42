#ifndef MENU_H
# define MENU_H

# define MENU_BUTTON_WIDTH 250
# define MENU_BUTTON_HEIGHT 50
# define MENU_BUTTON_PADDING 20
# define MENU_TEXT_COLOR 0xA0E0E0
# define MENU_BUTTON_COLOR 0xBE1A2A4C
# define MENU_DIM 100

# include "types.h"

typedef enum e_state
{
	PLAYING,
	MENU
}	t_state;

typedef struct s_menu_item
{
	char	*text;
	void	(*caller)(t_engine *eng);
}	t_menu_item;

typedef struct s_menu
{
	t_menu_item	*main;
	int			size;
	bool		is_drawn;
}	t_menu;

void	menu_switch_state(t_engine *eng);
void	set_items(t_engine *eng);
void	render_menu(t_engine *eng);

#endif
