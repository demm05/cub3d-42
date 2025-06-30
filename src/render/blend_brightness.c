/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_brightness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:58:11 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 15:33:26 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

 t_ui	blend_brightness_f(t_ui color, float brightness)
{
	int	r;
	int	g;
	int	b;
	int	brightness_fixed;

	if (brightness >= 1.0)
		return (color);
	if (brightness <= 0.0)
		return (0);
	brightness_fixed = (int)(brightness * 256.0);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (r * brightness_fixed) >> 8;
	g = (g * brightness_fixed) >> 8;
	b = (b * brightness_fixed) >> 8;
	return ((r << 16) | (g << 8) | b);
}

 t_ui	blend_brightness(t_ui color, unsigned char brightness)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (r * brightness) >> 8;
	g = (g * brightness) >> 8;
	b = (b * brightness) >> 8;
	return ((r << 16) | (g << 8) | b);
}
