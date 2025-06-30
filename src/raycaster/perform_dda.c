/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:49:44 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/26 17:07:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_private.h"

static MAYBE_INLINE void	dda(t_ray *ray)
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

static MAYBE_INLINE bool	is_door(t_ray *ray, t_engine *eng, t_door *hit_door)
{
	double	open_side;
	double	left;
	double	right;

	ray->is_door = true;
	if (hit_door->animation <= 0.0)
	{
		ray->door_ptr = hit_door;
		return (1);
	}
	if (ray->side == 0)
		ray->wall_hit = eng->camera.pos.y + ray->wall_dist * ray->direction.y;
	else
		ray->wall_hit = eng->camera.pos.x + ray->wall_dist * ray->direction.x;
	ray->wall_hit -= floor(ray->wall_hit);
	open_side = hit_door->animation;
	left = 0.5 - open_side / 2.0;
	right = 0.5 + open_side / 2.0;
	if (ray->wall_hit <= left || ray->wall_hit >= right)
	{
		ray->door_ptr = hit_door;
		return (1);
	}
	else
		return (0);
}

static MAYBE_INLINE bool	handle_door_hit(t_ray *ray,
	t_engine *eng, t_door *door)
{
	t_door	*nearby;

	if (!door->is_open)
	{
		nearby = get_nearby_closed_door(&eng->camera, &eng->doors);
		if (nearby == door && eng->input.opening_door)
			handle_door_interaction(door, &eng->input.opening_door);
		else
			eng->input.opening_door = 0;
	}
	if (is_door(ray, eng, door))
		return (true);
	else
		return (false);
}

MAYBE_INLINE void	perform_dda(t_ray *ray, t_engine *eng)
{
	char	tile;
	t_door	*hit_door;

	while (1)
	{
		dda(ray);
		if (!ray->side)
			ray->wall_dist = ray->side_dist.x - ray->delta.x;
		else
			ray->wall_dist = ray->side_dist.y - ray->delta.y;
		tile = get_tile_with_doors(&eng->doors, ray->map.x,
				ray->map.y, eng->map->matrix);
		hit_door = get_door_by_pos(&eng->doors, ray->map.x, ray->map.y);
		if (hit_door)
		{
			if (handle_door_hit(ray, eng, hit_door))
				return ;
			else
				continue ;
		}
		else if (tile >= '1' && tile <= '9')
			return ;
	}
}
