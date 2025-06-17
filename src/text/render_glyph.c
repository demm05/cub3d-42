#include "text_private.h"

MAYBE_INLINE void	text_render_glyph(t_engine *eng, FT_Face face, t_point baseline, t_ui color)
{
	FT_GlyphSlot	slot;
	FT_Bitmap		*bitmap;
	t_point			bmp;
	t_point			offset;
	t_point			screen;

	slot = face->glyph;
	bitmap = &slot->bitmap;
	offset.x = baseline.x + slot->bitmap_left;
	offset.y = baseline.y - slot->bitmap_top;
	bmp.y = -1;
	while (++bmp.y < (int)bitmap->rows)
	{
		bmp.x = -1;
		screen.y = offset.y + bmp.y;
		if (screen.y < 0 || screen.y >= eng->window.height)
			continue ;
		while (++bmp.x < (int)bitmap->width)
		{
			screen.x = offset.x + bmp.x;
			if (screen.x < 0 || screen.x >= eng->window.width)
				continue ;
			if (bitmap->buffer[bmp.y * bitmap->width + bmp.x] > 0)
				draw_pixel(&eng->main_buffer, screen.x, screen.y, color);
		}
	}
}
