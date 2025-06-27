/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:52 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:52 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

/**
 * Efficiently blends a single color channel using integer arithmetic.
 * Approximates division by 255 using multiplication and bit-shift.
 * alpha is for the foreground channel (0-255).
 * (Source_Color × Source_Alpha) + (Destination_Color × (1 - Source_Alpha))
*/
static inline t_ui	blend_channel_fast(t_ui fg_channel, t_ui bg_channel, t_ui alpha)
{
	return (((fg_channel * alpha + bg_channel * (255 - alpha)) * 257U) >> 16);
}

MAYBE_INLINE t_ui	blend_normal(t_ui source, t_ui dest)
{
	t_rgb	s;
	t_rgb	d;
	t_rgb	r;
	t_ui	alpha;

	alpha = (dest >> 24) & 0xFF;
	if (alpha == 0)
		return (source);
	if (alpha == 255)
		return (dest);
	s.red = (source >> 16) & 0xFF;
	s.green = (source >> 8) & 0xFF;
	s.blue = source & 0xFF;
	d.red = (dest >> 16) & 0xFF;
	d.green = (dest >> 8) & 0xFF;
	d.blue = dest & 0xFF;
	r.red = blend_channel_fast(d.red, s.red, alpha);
	r.green = blend_channel_fast(d.green, s.green, alpha);
	r.blue = blend_channel_fast(d.blue, s.blue, alpha);
	return (((r.red & 0xFF) << 16) | ((r.green & 0xFF) << 8) | (r.blue & 0xFF));
}

MAYBE_INLINE t_ui	blend_brightness_f(t_ui color, float brightness)
{
	int	r;
	int	g;
	int	b;
	int	brightness_fixed;

	if (brightness >= 1.0)
		return (color);
	if (brightness <= 0.0)
		return (0);
	// Convert brightness (0.0-1.0) to a fixed-point integer (0-256)
	brightness_fixed = (int)(brightness * 256.0);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (r * brightness_fixed) >> 8;
	g = (g * brightness_fixed) >> 8;
	b = (b * brightness_fixed) >> 8;
	return ((r << 16) | (g << 8) | b);
}

MAYBE_INLINE t_ui	blend_brightness(t_ui color, unsigned char brightness)
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

MAYBE_INLINE void	blend_normal_a(t_engine *eng, t_point p, t_ui dest, unsigned char alpha)
{
	t_ui	*source;
	t_rgb	s;
	t_rgb	d;
	t_rgb	r;

	source = get_pixel_address(&eng->main_buffer, p.x, p.y);
	s.red = (*source >> 16) & 0xFF;
	s.green = (*source >> 8) & 0xFF;
	s.blue = *source & 0xFF;
	d.red = (dest >> 16) & 0xFF;
	d.green = (dest >> 8) & 0xFF;
	d.blue = dest & 0xFF;
	r.red = blend_channel_fast(d.red, s.red, alpha) & 0xFF;
	r.green = blend_channel_fast(d.green, s.green, alpha) & 0xFF;
	r.blue = blend_channel_fast(d.blue, s.blue, alpha) & 0xFF;
	*source = r.red << 16 | r.green << 8 | r.blue;
}

MAYBE_INLINE void	blend_normal_at(t_engine *eng, int x, int y, t_ui dest)
{
	t_ui	*source;

	source = get_pixel_address(&eng->main_buffer, x, y);
	*source = blend_normal(*source, dest);
}
