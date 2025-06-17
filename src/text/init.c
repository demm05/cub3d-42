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
	return (1);
}

void	text_destroy(t_engine *eng)
{
	t_freetype	*fr;

	if (!eng || !eng->freetype)
		return ;
	fr = eng->freetype;
	if (fr->library)
    	FT_Done_FreeType(fr->library);
    if (fr->main)
		FT_Done_Face(fr->main);
	free(fr);
	eng->freetype = NULL;
}
