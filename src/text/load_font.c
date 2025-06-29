/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:30:18 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_private.h"

static inline bool	load_font(t_freetype *fr, FT_Face *dest,
						const char *path, int face_index)
{
	if (!dest || !path)
		return (FAILURE);
	if (FT_New_Face(fr->library, path, face_index, dest))
		return (error_log("text_load_font: failed to load font %s\n", path));
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
		return (error_log("text_load_font: path is missing\n"), NULL);
	if (!fr || !fr->library)
		return (error_log("text_load_font: freetype is missing or not"
				"initialized\n"), NULL);
	if (load_font(fr, &face, path, 0) == FAILURE)
		return (NULL);
	return (face);
}

bool	text_load_fonts(t_freetype *fr, const char *dir)
{
	char	**names;
	int		len;

	if (!dir)
		return (error_log("dir for fonts is missing\n"));
	if (!fr || !fr->library)
		return (error_log("text_load_font: freetype is missing or not"
				"initialized\n"));
	names = get_files_from_dir(dir, ".ttf"); 
	if (!names)
		return (FAILURE);
	len = split_len(names);
	fr->matrix = ft_realloc(fr->matrix,
		sizeof(FT_Face) * (len + fr->faces_loaded + 1));
	if (!fr->matrix)
		return (free_str_arr(names), error_log("malloc error\n"));
	load_fonts(fr, names, len);
	if (EXPECTED_NUM_OF_FONTS > fr->faces_loaded)
		return (free_str_arr(names), error_log("expected %d fonts at %s\n", dir));
	free_str_arr(names);
	fr->matrix[len] = NULL;
	return (SUCCESS);
}
