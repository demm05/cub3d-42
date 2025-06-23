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

static MAYBE_INLINE void	perform_dda(t_ray *ray, t_map *wrd)
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
		if (map_get(wrd, ray->map.x, ray->map.y) > 0)
			return ;
	}
}

MAYBE_INLINE void	cast_ray(t_engine *eng, t_ray *ray, int h, int w)
{
	set_values(ray, &eng->camera, w);
	set_direction(ray, &eng->camera);
	perform_dda(ray, eng->map);
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
