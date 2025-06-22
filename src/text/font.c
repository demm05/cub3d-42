#include "text_private.h"

void	text_set_font_size(t_engine *eng, int size, int font)
{
    FT_Set_Pixel_Sizes(eng->freetype->matrix[font], 0, size);
}
