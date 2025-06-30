/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:21 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:30:21 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_private.h"

MAYBE_INLINE void	text_put_char(t_engine *eng, t_point start, const char c, unsigned int color)
{
	FT_Face	face;

	if (!eng || !eng->freetype || !eng->freetype->faces_loaded)
		return ;
	face = eng->freetype->matrix[0];
	if (!face || FT_Load_Char(face, c, FT_LOAD_RENDER))
		return ;
	text_render_glyph(eng, face, start, color);
}

MAYBE_INLINE void	text_put_str(t_engine *eng, t_point start, const char *str, unsigned int color)
{
	FT_Face		face;
	t_point		pen;
	const char	*ptr;

	if (!str || !eng || !eng->freetype || !eng->freetype->faces_loaded)
		return ;
	face = eng->freetype->matrix[0];
	if (!face)
		return ;
	pen = start;
	ptr = str;
	while (*ptr)
	{
		if (FT_Load_Char(face, *ptr, FT_LOAD_RENDER))
		{
			ptr++;
			continue ;
		}
		if (ptr == str)
			pen.y += face->glyph->bitmap_top;
		text_render_glyph(eng, face, pen, color);
		pen.x += face->glyph->advance.x >> 6;
		pen.y += face->glyph->advance.y >> 6;
		ptr++;
	}
}

MAYBE_INLINE t_point	text_str_get_size(t_engine *eng, const char *str, int font)
{
	FT_Face	face;
	t_point	res;

	res.x = 0;
	res.y = 0;
	if (!str || !eng || !eng->freetype || !eng->freetype->faces_loaded)
		return (res);
	face = eng->freetype->matrix[font];
	if (!face)
		return (res);
	while (*str)
	{
		if (!FT_Load_Char(face, *str++, FT_LOAD_RENDER))
		{
			res.x += face->glyph->advance.x >> 6;
			if ((int)face->glyph->bitmap.rows > res.y)
				res.y = face->glyph->bitmap.rows;
		}
	}
	return (res);
}

