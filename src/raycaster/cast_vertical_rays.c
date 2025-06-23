/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vertical_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:32 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:33 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_private.h"
#include <math.h>

static MAYBE_INLINE void	set_values(t_ray *ray, t_camera *cam, double w)
{
	double	camera_x;

	ray->is_door = false;
	ray->door_ptr = NULL;
	camera_x = 2 * (w - ray->index) / w - 1;
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

static MAYBE_INLINE void	dda(t_ray *ray, t_engine *eng)
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
}

static MAYBE_INLINE void	perform_dda_door(t_ray *ray, t_engine *eng)
{
	char	tile;
	t_door	*hit_door;
	t_door	*nearby;

	while (1)
	{
		dda(ray, eng);

		// Обчисли dist
		if (!ray->side)
			ray->wall_dist = ray->side_dist.x - ray->delta.x;
		else
			ray->wall_dist = ray->side_dist.y - ray->delta.y;
		// Обчисли tile
		tile = get_tile_with_doors(&eng->doors, ray->map.x,
				ray->map.y, eng->map->matrix);

		// Шукаємо двері
		hit_door = get_door_by_pos(&eng->doors, ray->map.x, ray->map.y);

		if (hit_door && !hit_door->is_open)
		{
			nearby = get_nearby_closed_door(&eng->camera, &eng->doors);
			if (nearby == hit_door && eng->input.opening_door)
				handle_door_interaction(&eng->camera, nearby,
					&eng->input.opening_door);
			else
				eng->input.opening_door = 0;
		}

		if (hit_door)
		{
			ray->is_door = true;
			if (hit_door->animation <= 0.0)
			{
				ray->door_ptr = hit_door;
				return ;
			}

			// Обчислення wall_hit
			if (ray->side == 0)
				ray->wall_hit = eng->camera.pos.y + ray->wall_dist * ray->direction.y;
			else
				ray->wall_hit = eng->camera.pos.x + ray->wall_dist * ray->direction.x;
			ray->wall_hit -= floor(ray->wall_hit);

			double open_side = hit_door->animation;
			double left = 0.5 - open_side / 2.0;
			double right = 0.5 + open_side / 2.0;

			if (ray->wall_hit <= left || ray->wall_hit >= right)
			{
				ray->door_ptr = hit_door;
				return ;
			}
			else
				continue ; // промінь проходить далі
		}
		else if (tile >= '1' && tile <= '9')
			return ;
	}
}

static MAYBE_INLINE void	perform_dda(t_ray *ray, t_engine *eng)
{
	char	tile;

	while (1)
	{
		dda(ray, eng);
		tile = get_tile_with_doors(&eng->doors, ray->map.x,
				ray->map.y, eng->map->matrix);
		if (tile >= '1' && tile <= '9')
			return ;
	}
}

MAYBE_INLINE void	cast_door(t_engine *eng, t_ray *ray, int h, int w)
{
	set_values(ray, &eng->camera, w);
	set_direction(ray, &eng->camera);
	perform_dda_door(ray, eng);

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

	ray->brightness = 1.0 - (ray->wall_dist / FOG_DISTANCE);
	if (ray->brightness < 0)
		ray->brightness = 0;
	// ray_set_door_prop(eng, ray);
	ray_set_wall_prop(eng, ray);
	// ray_set_floor_prop(eng, ray);
}

MAYBE_INLINE void	cast_ray(t_engine *eng, t_ray *ray, int h, int w)
{
	set_values(ray, &eng->camera, w);
	set_direction(ray, &eng->camera);
	perform_dda_door(ray, eng);

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

	ray->brightness = 1.0 - (ray->wall_dist / FOG_DISTANCE);
	if (ray->brightness < 0)
		ray->brightness = 0;
	ray_set_wall_prop(eng, ray);
	ray_set_floor_prop(eng, ray);
}
