/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:41:12 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/26 17:06:39 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_private.h"

static void	private_set_defaults(t_door_private_state *state)
{
	state->max_dist = 2.5;
	state->max_offset = 0.5;
	state->nearest = NULL;
	state->best_dot = -1.0;
}

static void	set_nearby_door(t_door_private_state *state,
	t_door *door, t_camera *player)
{
	if (door->is_open)
		return ;
	state->dx = (door->x + 0.5) - player->pos.x;
	state->dy = (door->y + 0.5) - player->pos.y;
	state->dist = sqrt(state->dx * state->dx + state->dy * state->dy);
	if (state->dist > state->max_dist)
		return ;
	state->door_vec.x = state->dx / state->dist;
	state->door_vec.y = state->dy / state->dist;
	state->perp.x = -player->dir.y;
	state->perp.y = player->dir.x;
	state->offset = fabs(state->perp.x * state->dx + state->perp.y * state->dy);
	if (state->offset > state->max_offset)
		return ;
	state->dot = state->door_vec.x * player->dir.x
		+ state->door_vec.y * player->dir.y;
	if (state->dot > state->best_dot)
	{
		state->best_dot = state->dot;
		state->nearest = door;
	}
}

t_door	*get_nearby_closed_door(t_camera *player, t_doors *doors)
{
	t_door					*door;
	t_door_private_state	state;
	int						i;

	i = 0;
	private_set_defaults(&state);
	while (i < doors->len)
	{
		door = &doors->doors[i];
		set_nearby_door(&state, door, player);
		if (state.nearest)
			return (state.nearest);
		i++;
	}
	return (state.nearest);
}

void	handle_door_interaction(t_door *door, bool *opening_door)
{
	if (!*opening_door || door->animation != 0.0)
		return ;
	if (door)
	{
		door->ready_to_open = true;
		door->start_time = get_time_ms();
	}
	*opening_door = false;
}

char	get_tile_with_doors(t_doors *doors, int x, int y, char **map)
{
	int	i;

	i = 0;
	while (i < doors->len)
	{
		if (doors->doors[i].x == x && doors->doors[i].y == y)
		{
			if (doors->doors[i].is_open)
				return ('0');
			else
				return ('d');
		}
		i++;
	}
	return (map[y][x]);
}
