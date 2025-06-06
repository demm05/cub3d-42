#include "render_private.h"

/**
 * Efficiently blends a single color channel using integer arithmetic.
 * Approximates division by 255 using multiplication and bit-shift.
 * alpha is for the foreground channel (0-255).
 * (Source_Color × Source_Alpha) + (Destination_Color × (1 - Source_Alpha))
*/
static t_ui	blend_channel_fast(t_ui fg_channel, t_ui bg_channel, t_ui alpha)
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
