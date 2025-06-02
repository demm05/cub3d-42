#include "raycaster_private.h"

MAYBE_INLINE int	get_pixel_color(t_image *img, int x, int y)
{
	char	*pixel_addr;
	int		color;

	pixel_addr = img->buffer + (y * img->line_size) + (x * (img->depth / 8));
	color = *(int *)pixel_addr;
	return (color);
}

inline int	color_vertical(int x, int y, void *param)
{
	t_engine	*eng;
	t_image		*tex;
	int			tex_x;
	int			tex_y;
	t_ray		*ray;

	eng = param;
	ray = &eng->rays[x];
	if (y < ray->draw_start)
		return (eng->world.c);
	if (y >= ray->draw_end)
		return (eng->world.f);
	tex = ray->texture;
    tex_x = ray->x_on_tex;
	if (ray->line_height <= 0)
		return (get_pixel_color(tex, tex_x, 0));
	else
        tex_y = (((y * 512 - eng->window.height * 256 + ray->line_height * 256) * tex->height) / ray->line_height) / 512;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	return (get_pixel_color(tex, tex_x, tex_y));
}

void	render(t_engine *eng)
{
	int	w;
	int	h;
	int	x;

	h = eng->window.height;
	w = eng->window.width;
	x = -1;
	while (++x < w)
		cast_ray(eng, &eng->rays[x], h, w);
	draw_for_each_pixel(&eng->main_buffer, eng, w, h, color_vertical);
}
