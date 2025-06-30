/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_glyph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:30:26 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_private.h"

MAYBE_INLINE void	text_render_glyph(t_engine *eng, FT_Face face, t_point baseline, t_ui color)
{
	FT_GlyphSlot	slot;
	FT_Bitmap		*bitmap;
	t_point			bmp;
	t_point			offset;
	t_point			screen;

	bmp.y = -1;
	slot = face->glyph;
	bitmap = &slot->bitmap;
	offset.x = baseline.x + slot->bitmap_left;
	offset.y = baseline.y - slot->bitmap_top;
	if (offset.y < 0)
		bmp.y = offset.y * -1 - 1;
	while (++bmp.y < (int)bitmap->rows)
	{
		bmp.x = -1;
		screen.y = offset.y + bmp.y;
		if (screen.y >= eng->window.height)
			break;
		if (offset.x < 0)
			bmp.x = offset.x * -1 - 1;
		while (++bmp.x < (int)bitmap->width)
		{
			screen.x = offset.x + bmp.x;
			if (screen.x > eng->window.width)
				break;
			blend_normal_a(eng, screen, color, bitmap->buffer[bmp.y * bitmap->width + bmp.x]);
		}
	}
}
