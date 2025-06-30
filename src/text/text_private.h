/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:28 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 12:01:39 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_PRIVATE_H 
# define TEXT_PRIVATE_H

# include "cube.h"

# include <ft2build.h>
# include <freetype2/freetype/freetype.h>
// # include FT_FREETYPE_H

typedef struct s_freetype
{
	FT_Library		library;
	unsigned int	faces_loaded;
	FT_Face			*matrix;
}	t_freetype;

void	text_free_fonts(t_freetype *fr);
void	text_render_glyph(t_engine *eng, FT_Face face,
			t_point baseline, t_ui color);

#endif
