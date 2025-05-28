#include "raycaster_private.h"
#include <math.h>

// char	g_world_map[MAP_HEIGHT][MAP_WIDTH] = {
// {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '2', '2', '2', '2', '2', '0', '0', '0', '0', '3', '0', '3', '0', '3', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '2', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '2', '0', '0', '0', '2', '0', '0', '0', '0', '3', '0', '0', '0', '3', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '2', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '2', '2', '0', '2', '2', '0', '0', '0', '0', '3', '0', '3', '0', '3', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '4', '4', '4', '4', '4', '4', '4', '4', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '4', '0', '4', '0', '0', '0', '0', '4', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '4', '0', '0', '0', '0', '5', '0', '4', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '4', '0', '4', '0', '0', '0', '0', '4', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '4', '0', '4', '4', '4', '4', '4', '4', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '4', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '4', '4', '4', '4', '4', '4', '4', '4', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
// };

static inline void	set_values(t_ray *ray, t_camera *cam, int x, double w)
{
	double	camera_x;

	camera_x = 2 * x / w - 1;
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
static inline void	set_direction(t_ray *ray, t_camera *cam)
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

static inline void	perform_dda(t_ray *ray)
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
		if (ray->map.y < (int)g_world.map->height && ray->map.x < (int)g_world.map->width
			&& g_world.map->matrix[ray->map.y][ray->map.x] > '0' && g_world.map->matrix[ray->map.y][ray->map.x] < '9')
			break ;
		else if (ray->map.y >= (int)g_world.map->height && ray->map.x >= (int)g_world.map->width)
			break ;
	}
}

int	get_pixel_color(t_image *img, int x, int y)
{
	char	*pixel_addr;
	int		color;

	pixel_addr = img->buffer + (y * img->line_size) + (x * (img->depth / 8));
	color = *(int *)pixel_addr;
	return (color);
}

MAYBE_INLINE void	draw_vert_img_line(t_frame_buf *buf, t_image *img,
		int x, int start, int end)
{
	if (start > end)
		return ;
	if (start < 0)
	{
		end += start;
		start = 0;
	}
	if (end > buf->height)
		end = buf->height;
	while (start < end)
	{
		draw_pixel(buf, x, start, get_pixel_color(img, x, start));
		start++;
	}
}

static inline void	draw(t_frame_buf *buf, t_ray *ray, t_image *tex, t_engine *eng, int x, int h)
{
	int		line_height;
	int		draw_start;
	int		draw_end;

	line_height = h / ray->wall_dist;
	draw_start = -line_height / 2 + h / 2;
	draw_end = line_height / 2 + h / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end > h)
		draw_end = h;

	// Коректне обчислення, який "кусок" текстури (tex_x) брати
	double	wall_hit;
	if (ray->side == 0)
		wall_hit = eng->camera.pos.y + ray->wall_dist * ray->direction.y;
	else
		wall_hit = eng->camera.pos.x + ray->wall_dist * ray->direction.x;

	wall_hit -= floor(wall_hit);
	int tex_x = (int)(wall_hit * (double)tex->width);

	// Трохи "дзеркальне" відображення для правих/верхніх стін
	if ((ray->side == 0 && ray->direction.x > 0) || (ray->side == 1 && ray->direction.y < 0))
		tex_x = tex->width - tex_x - 1;

	// СТЕЛЯ
	draw_vert_line(buf, x, 0, draw_start, g_world.c);

	// СТІНА (з правильним tex_x!)
	for (int y = draw_start; y < draw_end; y++)
	{
		int d = y * 256 - h * 128 + line_height * 128;
		int tex_y = ((d * tex->height) / line_height) / 256;

		int color = get_pixel_color(tex, tex_x, tex_y);
		draw_pixel(buf, x, y, color);
	}

	// ПІДЛОГА
	draw_vert_line(buf, x, draw_end, h, g_world.f);
}


// static inline void	draw(t_frame_buf *buf, t_ray *ray, t_image *tex, int x, int h)
// {
// 	int	line_height = h / ray->wall_dist;
// 	int	draw_start = -line_height / 2 + h / 2;
// 	int	draw_end = line_height / 2 + h / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	if (draw_end > h)
// 		draw_end = h;

// 	// 🟢 Спочатку малюємо СТЕЛЮ
// 	draw_vert_line(buf, x, 0, draw_start, g_world.c);

// 	// 🔵 Потім малюємо СТІНУ (з текстури)
// 	int tex_x = (int)( (double)x / (double)buf->width * tex->width );
// 	for (int y = draw_start; y < draw_end; y++)
// 	{
// 		int d = y * 256 - h * 128 + line_height * 128;
// 		int tex_y = ((d * tex->height) / line_height) / 256;

// 		int color = get_pixel_color(tex, tex_x, tex_y);
// 		draw_pixel(buf, x, y, color);
// 	}

// 	// 🔴 Нарешті малюємо ПІДЛОГУ
// 	draw_vert_line(buf, x, draw_end, h, g_world.f);
// }



// static inline void	draw(t_frame_buf *buf, t_ray *ray, int x, int h)
// {
// 	int	line_height;
// 	int	draw_start;
// 	int	draw_end;
// 	int	color;

// 	line_height = h / ray->wall_dist;
// 	draw_start = -line_height / 2 + h / 2;
// 	draw_end = line_height / 2 + h / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	if (draw_end > h)
// 		draw_end = h;
// 	color = 0xD2B48C;
// 	if (ray->side)
// 		color = color / 2;
// 	draw_vert_line(buf, x, 0, draw_start, 0x6490E0);
// 	draw_vert_line(buf, x, draw_start, draw_end, color);
// 	// draw_rectangle(buf, x, draw_start, 32, 32, 0);
// 	draw_vert_line(buf, x, draw_end, h, 0x804000);
// }

// MAYBE_INLINE void	draw_walls(t_engine *eng, t_ray *ray)
// {
// 	int	x;
// 	int	w;

// 	x = -1;
// 	w = eng->window.width;
// 	while (++x < w)
// 	{
// 		set_values(ray, &eng->camera, x, w);
// 		set_direction(ray, &eng->camera);
// 		perform_dda(ray);
// 		if (!ray->side)
// 			ray->wall_dist = ray->side_dist.x - ray->delta.x;
// 		else
// 			ray->wall_dist = ray->side_dist.y - ray->delta.y;
// 		draw(&eng->main_buffer, ray, x, eng->window.height);
// 	}
// }


MAYBE_INLINE void	draw_walls(t_engine *eng, t_ray *ray)
{
	int		x;
	int		w;
	t_image	*tex;

	x = -1;
	w = eng->window.width;
	while (++x < w)
	{
		set_values(ray, &eng->camera, x, w);
		set_direction(ray, &eng->camera);
		perform_dda(ray);
		if (!ray->side)
			ray->wall_dist = ray->side_dist.x - ray->delta.x;
		else
			ray->wall_dist = ray->side_dist.y - ray->delta.y;
		if (ray->side == 0 && ray->direction.x > 0)
			tex = &g_world.ea;
		else if (ray->side == 0 && ray->direction.x < 0)
			tex = &g_world.we;
		else if (ray->side == 1 && ray->direction.y > 0)
			tex = &g_world.so;
		else
			tex = &g_world.no;
		draw(&eng->main_buffer, ray, tex, eng, x, eng->window.height);
	}
}
