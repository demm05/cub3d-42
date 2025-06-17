#ifndef TEXT_PRIVATE_H 
# define TEXT_PRIVATE_H

# include "cube.h"

# include <ft2build.h>
# include FT_FREETYPE_H

typedef struct s_freetype
{
	FT_Library		library;
	FT_Face			main;
	unsigned int	faces_loaded;
}	t_freetype;

#endif
