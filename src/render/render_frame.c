#include "render_private.h"

t_ui	color_background(t_engine *eng, int x, int y, unsigned int color);

MAYBE_INLINE void	render_frame(t_engine *eng)
{
	int	w;
	int	h;
	int	x;

	h = eng->window.height;
	w = eng->window.width;
	x = -1;
	while (++x < w)
		cast_ray(eng, &eng->rays[x], h, w);
	draw_for_each_pixel(eng, (t_point){w, h}, color_background);
	if (eng->input.minimap_toggle)
		draw_minimap(eng);
}

MAYBE_INLINE t_ui	color_c(t_ray *ray, t_engine *eng, int h, int y)
{
	t_vec2_double	floor_pos;
	t_point			floor_tex;
	double			weight;

	(void)h;
	weight = eng->table.y[y].floor_dist / ray->wall_dist;
	floor_pos.x = weight * ray->floor_wall.x + (1.0 - weight) * eng->camera.pos.x;
	floor_pos.y = weight * ray->floor_wall.y + (1.0 - weight) * eng->camera.pos.y;
	floor_tex.x = (int)(floor_pos.x * eng->textures.ceiling.width) & (eng->textures.ceiling.width - 1);
	floor_tex.y = (int)(floor_pos.y * eng->textures.ceiling.height) & (eng->textures.ceiling.height - 1);
	return (get_pixel_color(&eng->textures.ceiling, floor_tex.x, floor_tex.y));
}

MAYBE_INLINE t_ui	color_f(t_ray *ray, t_engine *eng, int h, int y)
{
	t_vec2_double	floor_pos;
	t_point			floor_tex;
	double			weight;

	(void)h;
	weight = eng->table.y[y].floor_dist / ray->wall_dist;
	floor_pos.x = weight * ray->floor_wall.x + (1.0 - weight) * eng->camera.pos.x;
	floor_pos.y = weight * ray->floor_wall.y + (1.0 - weight) * eng->camera.pos.y;
	floor_tex.x = (int)(floor_pos.x * eng->textures.floor.width) & (eng->textures.floor.width - 1);
	floor_tex.y = (int)(floor_pos.y * eng->textures.floor.height) & (eng->textures.floor.height - 1);
	return (get_pixel_color(&eng->textures.floor, floor_tex.x, floor_tex.y));
}

MAYBE_INLINE t_ui	color_wall(t_ray *ray, int h, int y)
{
	t_image		*tex; 
	int			tex_x;
	int			tex_y;

	tex = ray->texture;
    tex_x = ray->x_on_tex;
	if (ray->line_height <= 0)
		return (get_pixel_color(tex, tex_x, 0));
	else
        tex_y = (((y * 256 - h * 128 + ray->line_height * 128) * tex->height) / ray->line_height) >> 8;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	return (get_pixel_color(tex, tex_x, tex_y));
}

MAYBE_INLINE t_ui	color_background(t_engine *eng, int x, int y, t_ui color)
{
	t_ray	*ray;

	(void)color;
	ray = &eng->rays[x];
	if (y < ray->draw_start)
	#if ENABLE_FOG
		return (blend_brightness(color_c(ray, eng, eng->window.height, y), eng->table.y[y].brightness));
	#else
		return (color_cf(ray, eng, eng->window.height, y));
	#endif
	else if (y >= ray->draw_end)
	#if ENABLE_FOG
		return (blend_brightness(color_f(ray, eng, eng->window.height, y), eng->table.y[y].brightness));
	#else
		return (color_cf(ray, eng, eng->window.height, y));
	#endif
	else
	#if ENABLE_FOG
		return (blend_brightness(color_wall(ray, eng->window.height, y), ray->brightness));
	#else
		return (color_wall(ray, eng->window.height, y));
	#endif
}

