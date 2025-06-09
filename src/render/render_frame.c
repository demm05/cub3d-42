#include "render_private.h"

t_ui	color_wall(t_ray *ray, int h, int y);
MAYBE_INLINE t_ui	color_cf(t_ray *ray, t_camera *cam, int h, int y);

MAYBE_INLINE unsigned int	color_background(t_engine *eng, int x, int y, unsigned int color)
{
	t_ray		*ray;

	(void)color;
	ray = &eng->rays[x];
	if (y < ray->draw_start || y >= ray->draw_end)
		return (color_cf(ray, &eng->camera, eng->window.height, y));
	// if (y < ray->draw_start)
	// 	return (eng->world.c);
	// else if (y >= ray->draw_end)
	// 	return (eng->world.f);
	else
		return (color_wall(ray, eng->window.height, y));
}

MAYBE_INLINE void	test(t_engine *eng, int h, int w)
{
	t_image	*floor_texture_1 = &eng->world.ea;
	t_image	*floor_texture_2 = &eng->world.so;
	t_image	*ceiling_texture = &eng->world.we;
	double	pos_x = eng->camera.pos.x;
	double	pos_y = eng->camera.pos.y;

	for (int x = 0; x < w; x++)
	{
		t_ray *ray = &eng->rays[x];
		int draw_end = ray->draw_end;
		if (draw_end < 0) draw_end = h;

		for (int y = draw_end; y < h; y++)
		{
			double current_dist = h / (2.0 * y - h);
			double weight = current_dist / ray->wall_dist;
			double current_floor_x = weight * ray->floor_x_wall + (1.0 - weight) * pos_x;
			double current_floor_y = weight * ray->floor_y_wall + (1.0 - weight) * pos_y;
			int floor_tex_x, floor_tex_y, color;
			if (((int)current_floor_x + (int)current_floor_y) % 2 == 0)
			{
				floor_tex_x = (int)(current_floor_x * floor_texture_1->width) & (floor_texture_1->width - 1);
				floor_tex_y = (int)(current_floor_y * floor_texture_1->height) & (floor_texture_1->height - 1);
				color = get_pixel_color(floor_texture_1, floor_tex_x, floor_tex_y);
			}
			else
			{
				floor_tex_x = (int)(current_floor_x * floor_texture_2->width) & (floor_texture_2->width - 1);
				floor_tex_y = (int)(current_floor_y * floor_texture_2->height) & (floor_texture_2->height - 1);
				color = get_pixel_color(floor_texture_2, floor_tex_x, floor_tex_y);
			}
			draw_pixel(&eng->main_buffer, x, y, (color >> 1) & 0x7F7F7F);
			int ceil_tex_x = (int)(current_floor_x * ceiling_texture->width) & (ceiling_texture->width - 1);
			int ceil_tex_y = (int)(current_floor_y * ceiling_texture->height) & (ceiling_texture->height - 1);
			if (h - y - 1 >= ray->draw_start)
				continue ;
			draw_pixel(&eng->main_buffer, x, h - y - 1, get_pixel_color(ceiling_texture, ceil_tex_x, ceil_tex_y));
		}
	}
}

void	render_frame(t_engine *eng)
{
	int	w;
	int	h;
	int	x;

	h = eng->window.height;
	w = eng->window.width;
	x = -1;
	while (++x < w)
	{
		cast_ray(eng, &eng->rays[x], h, w);
		ray_set_wall_prop(eng, &eng->rays[x]);
	}
	draw_for_each_pixel(eng, (t_point){w, h}, color_background);
	test(eng, h, w);
	if (eng->input.minimap_toggle)
		draw_minimap(eng);
}

MAYBE_INLINE t_ui	color_cf(t_ray *ray, t_camera *cam, int h, int y)
{
	// static float fx, fy;
	// int p;
	// p = h / 2 - y;
	// if (p == 0)
	// 	return (0);
	// float pos_z = 0.5 * h;
	// float row_distance = pos_z / p;
	// float floor_x = cam->pos.x + row_distance * (cam->dir.x - cam->plane.x);
	// float floor_y = cam->pos.y + row_distance * (cam->dir.y - cam->plane.y);
	// t_image	*tex = ray->texture;
	// int tx = (int)(tex->width * (floor_x - floorf(floor_x))) & (tex->width - 1);
	// int ty = (int)(tex->height * (floor_y - floorf(floor_y))) & (tex->height - 1);
	// return get_pixel_color(tex, tx, ty);
	return (0);
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
