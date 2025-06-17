#ifndef TEXT_H
# define TEXT_H

# include "cube.h"

bool	text_init(t_engine *eng);
void	text_destroy(t_engine *eng);
bool	text_load_font(t_freetype *fr, const char *var_name, const char *path);

#endif
