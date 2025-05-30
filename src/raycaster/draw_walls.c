/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:07 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/28 17:05:08 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_private.h"
#include <math.h>

static MAYBE_INLINE void	set_values(t_ray *ray, t_camera *cam, double w)
{
	double	camera_x;

	camera_x = 2 * ray->wall_x_cord / w - 1;
	// Calculates a direction of ray
	ray->direction.x = cam->dir.x + cam->plane.x * camera_x;
	ray->direction.y = cam->dir.y + cam->plane.y * camera_x;
	// Which box of map we're in
	ray->map.x = cam->pos.x;
	ray->map.y = cam->pos.y;
	// Length of ray from one x or y-side to next x or y-side
	// Prevents division by zero as well
	if (ray->direction.x == 0)
		ray->delta.x = 1e30;
	else
		ray->delta.x = fabs(1 / ray->direction.x);
	if (ray->direction.y == 0)
		ray->delta.y = 1e30;
	else
		ray->delta.y = fabs(1 / ray->direction.y);
}

// Sets in what direction ray should step in x or y direction
static MAYBE_INLINE void	set_direction(t_ray *ray, t_camera *cam)
{
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (cam->pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - cam->pos.x) * ray->delta.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (cam->pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - cam->pos.y) * ray->delta.y;
	}
}

static MAYBE_INLINE void	perform_dda(t_ray *ray, t_world *wrd)
{
	while (1)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (map_get(wrd, ray->map.x, ray->map.y) > '0')
			return ;
	}
}

static MAYBE_INLINE t_image	*get_texture(t_ray *ray, t_world *world, int h)
{
	if (!ray->side)
		ray->wall_dist = ray->side_dist.x - ray->delta.x;
	else
		ray->wall_dist = ray->side_dist.y - ray->delta.y;
	ray->line_height = h / ray->wall_dist;
	ray->draw_start = -ray->line_height / 2 + h / 2;
	ray->draw_end = ray->line_height / 2 + h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end > h)
		ray->draw_end = h;
	if (ray->side == 0 && ray->direction.x > 0)
		// ray->wall_face_hit = 0;
		return (&world->ea);
	else if (ray->side == 0 && ray->direction.x < 0)
		// ray->wall_face_hit = 1;
		return (&world->we);
	else if (ray->side == 1 && ray->direction.y > 0)
		// ray->wall_face_hit = 2;
		return (&world->so);
	else
		// ray->wall_face_hit = 3;
		return (&world->no);
}

static MAYBE_INLINE int	get_pixel_color(t_image *img, int x, int y)
{
	char	*pixel_addr;
	int		color;

	pixel_addr = img->buffer + (y * img->line_size) + (x * (img->depth / 8));
	color = *(int *)pixel_addr;
	return (color);
}

/* Like from guide
static MAYBE_INLINE void	draw_textured_wall(t_engine *eng, t_ray *ray, t_image *tex, int h)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		y;

	if (!ray->side)
		wall_x = eng->camera.pos.y + ray->wall_dist * ray->direction.y;
	else
		wall_x = eng->camera.pos.x + ray->wall_dist * ray->direction.x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->direction.x > 0) || (ray->side == 1 && ray->direction.y < 0))
		tex_x = tex->width - tex_x - 1;
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = (ray->draw_start - h / 2.0 + ray->line_height / 2.0) * step;
	y = -1;
	while (++y < ray->draw_end)
		draw_pixel(&eng->main_buffer, ray->wall_x_cord, y,
			get_pixel_color(tex, tex_x, tex->height * (int)tex_pos & (tex->height - 1)));
}
*/

static MAYBE_INLINE void	draw_textured_wall(t_engine *eng, t_ray *ray, t_image *tex, int h)
{
	double	wall_hit;
	int		tex_x;
	int		y;

	if (ray->side == 0)
		wall_hit = eng->camera.pos.y + ray->wall_dist * ray->direction.y;
	else
		wall_hit = eng->camera.pos.x + ray->wall_dist * ray->direction.x;
	wall_hit -= floor(wall_hit);
	tex_x = (int)(wall_hit * (double)tex->width);
	if ((ray->side == 0 && ray->direction.x > 0) || (ray->side == 1 && ray->direction.y < 0))
		tex_x = tex->width - tex_x - 1;
	y = ray->draw_start -1;
	while (++y < ray->draw_end)
	{
		int d = y * 256 - h * 128 + ray->line_height * 128;
		int tex_y = ((d * tex->height) / ray->line_height) / 256;
		int color = get_pixel_color(tex, tex_x, tex_y);
		draw_pixel(&eng->main_buffer, ray->wall_x_cord, y, color);
	}
}

MAYBE_INLINE void	cast_walls(t_engine *eng, t_ray *ray)
{
	int		w;
	int		h;
	t_image	*tex;

	ray->wall_x_cord = -1;
	h = eng->window.height;
	w = eng->window.width;
	while (++ray->wall_x_cord < w)
	{
		set_values(ray, &eng->camera, w);
		set_direction(ray, &eng->camera);
		perform_dda(ray, &eng->world);
		tex = get_texture(ray, &eng->world, h);
		draw_textured_wall(eng, &eng->ray, tex, h);
		draw_vert_line(&eng->main_buffer, ray->wall_x_cord, 0, ray->draw_start, eng->world.c);
		draw_vert_line(&eng->main_buffer, ray->wall_x_cord, ray->draw_end, h, eng->world.f);
	}
}
