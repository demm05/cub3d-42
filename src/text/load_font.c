#include "text_private.h"

static inline bool	load_font(t_freetype *fr, FT_Face *dest,
						const char *path, int face_index)
{
	if (!dest || !path)
		return (FAILURE);
	if (FT_New_Face(fr->library, path, face_index, dest))
		return (FF(STDERR_FILENO, RED"text_load_font: "RESET
				"failed to load %s\n", path), FAILURE);
	return (SUCCESS);
}

static inline void	load_fonts(t_freetype *fr, char **names, int len)
{
	int i;

	if (!fr || !names)
		return ;
	i = 0;
	while (i < len)
		if (load_font(fr, &fr->matrix[fr->faces_loaded], names[i++], 0) == SUCCESS)
			fr->faces_loaded++;
	return ;
}

void	*text_load_font(t_freetype *fr, const char *path)
{
	FT_Face	face;

	if (!path)
		return (FF(STDERR_FILENO, RED"text_load_font: "RESET
					"path is missing\n"), NULL);
	if (!fr || !fr->library)
		return (FF(STDERR_FILENO, RED"text_load_font: "RESET
					"freetype is missing or not initialized\n"), NULL);
	if (load_font(fr, &face, path, 0) == FAILURE)
		return (NULL);
	return (face);
}

bool	text_load_fonts(t_freetype *fr, const char *dir)
{
	char	**names;
	int		len;

	if (!dir)
		return (FAILURE);
	if (!fr || !fr->library)
		return (FF(STDERR_FILENO, RED"text_load_font: "RESET
			"freetype is missing or not initialized\n"), FAILURE);
	names = get_files_from_dir(dir, ".ttf"); 
	if (!names)
		return (FAILURE);
	len = split_len(names);
	fr->matrix = ft_realloc(fr->matrix,
		sizeof(FT_Face) * (len + fr->faces_loaded + 1));
	if (!fr->matrix)
		return (free_str_arr(names), FAILURE);
	load_fonts(fr, names, len);
	if (EXPECTED_NUM_OF_FONTS > fr->faces_loaded)
		return (free_str_arr(names), FAILURE);
	free_str_arr(names);
	fr->matrix[len] = NULL;
	return (SUCCESS);
}
