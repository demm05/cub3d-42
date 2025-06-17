#include "text_private.h"

bool	text_init(t_engine *eng)
{
	if (!eng)
		return (0);
	if (eng->freetype)
		text_destroy(eng);
	eng->freetype = ft_calloc(1, sizeof(t_freetype));
	if (!eng->freetype)
		return (0);
	if (FT_Init_FreeType(&eng->freetype->library))
		return (0);
	if (text_load_fonts(eng->freetype, FONTS_DIR) == FAILURE)
		return (0);
	return (1);
}

void	text_free_fonts(t_freetype *fr)
{
	unsigned int	i;

	if (!fr || !fr->matrix)
		return ;
	i = 0;
	while (i < fr->faces_loaded)
		FT_Done_Face(fr->matrix[i++]);
	free(fr->matrix);
	fr->faces_loaded = 0;
}

void	text_destroy(t_engine *eng)
{
	t_freetype	*fr;

	if (!eng || !eng->freetype)
		return ;
	fr = eng->freetype;
    text_free_fonts(fr);
	if (fr->library)
    	FT_Done_FreeType(fr->library);
	free(fr);
	eng->freetype = NULL;
}
