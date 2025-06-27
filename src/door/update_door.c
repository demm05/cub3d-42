/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:21:00 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/27 09:12:25 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_private.h"

static void	set_bool(bool *is_open, bool *ready_to_open, bool val1, bool val2)
{
	*is_open = val1;
	*ready_to_open = val2;
}

static MAYBE_INLINE void	open_door(t_door *door, t_map **map, size_t now)
{
	double	elapsed;

	if (door->is_closing)
	{
		door->is_closing = false;
		door->start_time = now
			- (size_t)(door->animation * (double)DOOR_ANIMATION_DURATION);
	}
	elapsed = now - door->start_time;
	door->animation = elapsed / DOOR_ANIMATION_DURATION;
	if (door->animation >= 0.5)
		(*map)->matrix[door->y][door->x] = '0';
	if (door->animation >= 1.0)
	{
		door->animation = 1.0;
		set_bool(&door->is_open, &door->ready_to_open, true, false);
		door->is_closing = false;
		door->start_time = now;
	}
}

static MAYBE_INLINE void	closing_door(t_door *door, t_map **map,
		double elapsed)
{
	elapsed = (elapsed - DOOR_OPEN_DURATION) / DOOR_ANIMATION_DURATION;
	if (elapsed > 1.0)
		elapsed = 1.0;
	door->animation = 1.0 - elapsed;
	if (door->animation <= 0.5)
		(*map)->matrix[door->y][door->x] = 'd';
	if (door->animation <= 0.0)
	{
		set_bool(&door->is_open, &door->is_closing, false, false);
		door->animation = 0.0;
	}
}

static MAYBE_INLINE void	close_door(t_door *door, t_map **map,
		t_camera *player, size_t now)
{
	const double	block_radius = 1.5;
	const double	dx = player->pos.x - (door->x + 0.5);
	const double	dy = player->pos.y - (door->y + 0.5);
	const double	dist = sqrt(dx * dx + dy * dy);
	double			elapsed;

	if (dist < block_radius && door->animation > 0.5)
	{
		door->is_closing = true;
		set_bool(&door->is_open, &door->ready_to_open, false, true);
		return ;
	}
	elapsed = now - door->start_time;
	if (elapsed < DOOR_OPEN_DURATION)
		return ;
	closing_door(door, map, elapsed);
}

MAYBE_INLINE void	update_doors(t_doors *doors, t_map **map,
		t_camera *player, double dt)
{
	t_door	*door;
	size_t	now;
	int		i;

	(void)dt;
	i = 0;
	while (i < doors->len)
	{
		door = &doors->doors[i];
		if (door->ready_to_open && !door->is_open)
		{
			now = get_time_ms();
			open_door(door, map, now);
		}
		else if (door->is_open)
		{
			now = get_time_ms();
			close_door(door, map, player, now);
		}
		i++;
	}
}
