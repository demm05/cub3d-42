#include "render_private.h"

MAYBE_INLINE void	render_health_bar(t_engine *eng)
{
	t_point	bar_size;
	t_point	offset;
	int		column_size;
	int		text_size;
	int		border_size;

	border_size = 3;
	if (eng->health < 0)
		eng->health = 100;
	bar_size.x = (eng->window.width >> 2) * eng->setting.ui_scale;
	bar_size.y = (eng->window.height >> 5) * eng->setting.ui_scale;
	column_size = bar_size.x / 100;
	text_size = bar_size.y * 0.7;
	offset.x = 20;
	offset.y = 20;
	render_rectangle_blend(eng, (t_point){offset.x - border_size, offset.y - border_size},
		(t_point){column_size * 100 + border_size * 2, bar_size.y + border_size * 2}, 0x99000001);
	draw_rectangle(eng, offset, (t_point){eng->health * column_size, bar_size.y}, 0xFF0000);
	text_set_font_size(eng, text_size, 0);
	bar_size = text_ui_get_size(eng, eng->health, 0);
	text_put_int(eng, (t_point){offset.x + 2, offset.y + bar_size.y * 0.35}, eng->health, 0);
}
