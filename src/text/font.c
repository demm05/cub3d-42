/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:13 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:30:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_private.h"

void	text_set_font_size(t_engine *eng, int size, int font)
{
    FT_Set_Pixel_Sizes(eng->freetype->matrix[font], 0, size);
}
