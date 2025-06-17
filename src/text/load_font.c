#include "text_private.h"

static inline bool	load_font(t_freetype *fr, FT_Face *dest,
						const char *path, int face_index)
{
	if (!dest || !path)
		return (FAILURE);
	if (FT_New_Face(fr->library, path, face_index, dest))
		return (FF(STDERR_FILENO, RED"text_load_font: "RESET
				"failed to load %d", path), FAILURE);
	fr->faces_loaded++;
	return (SUCCESS);
}

bool	text_load_font(t_freetype *fr, const char *var_name, const char *path)
{
	if (!var_name || !path)
		return (FF(STDERR_FILENO, RED"text_load_font: "RESET
					"var_name or path is missing"), FAILURE);
	if (!fr || !fr->library)
		return (FF(STDERR_FILENO, RED"text_load_font: "RESET
					"freetype is missing or not initialized"), FAILURE);
	if (ft_strstr("DEFAULT", var_name))
		return (load_font(fr, &fr->main, path, 0));
	return (FF(STDERR_FILENO, RED"text_load_font: "RESET
				"var_name is missing in t_freetype structure"));
}
