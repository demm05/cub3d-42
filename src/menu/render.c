#include "cube.h"

void	render_menu(t_engine *eng)
{
	t_menu	*m;
	t_point	start;
	t_point	button_pos;
	int		total_height;
	int		i;

	eng->draw_new_frame = 0;
	text_set_font_size(eng, MENU_BUTTON_HEIGHT * 0.6, 0);
	m = &eng->menu;
	total_height = (m->size * MENU_BUTTON_HEIGHT) + \
		((m->size - 1) * MENU_BUTTON_PADDING);
	start.y = (eng->window.height - total_height) / 2;
	button_pos.x = (eng->window.width - MENU_BUTTON_WIDTH) / 2;
	i = -1;
	while (++i < m->size)
	{
		button_pos.y = start.y + i * (MENU_BUTTON_HEIGHT + MENU_BUTTON_PADDING);
		render_rectangle_blend(eng, button_pos,
			(t_point){MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT}, MENU_BUTTON_COLOR);
		text_put_str(eng, button_pos, m->main[i].text, MENU_TEXT_COLOR);
	}
}
