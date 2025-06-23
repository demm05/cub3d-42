/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:41:12 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/23 15:45:09 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_private.h"

// bool	is_door(t_engine *eng)
// {
// 	if (eng->input.opening_door)
// 	{
// 		eng->input.opening_door = 0;
// 		if (eng->camera.pos.x + 1 == eng->door.x
// 			|| eng->camera.pos.y + 1 == eng->door.y
// 			|| eng->camera.pos.x - 1 == eng->door.x
// 			|| eng->camera.pos.y - 1 == eng->door.y
// 		)
// 		{
// 			eng->door.ready_to_open = 1;
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

void	print_door(t_door *door, char *state)
{
	printf("door: %s\n   x = %i\n   y = %i\n   anim = %f\n   timer = %f\n   is_open = %d\n   to_open = %d\n\n",
		state, door->x, door->y, door->animation, door->timer,
		door->is_open, door->ready_to_open);
}

// t_door	*get_nearby_closed_door(t_camera *player, t_doors *doors)
// {
// 	for (int i = 0; i < doors->len; i++)
// 	{
// 		t_door *door = &doors->doors[i];
// 		if (door->is_open)
// 			continue ;
// 		double dx = player->pos.x - (door->x + 0.5);
// 		double dy = player->pos.y - (door->y + 0.5);
// 		double dist = sqrt(dx * dx + dy * dy);
// 		if (dist < 2)
// 			return (door);
// 	}
// 	return (NULL);
// }
t_door	*get_nearby_closed_door(t_camera *player, t_doors *doors)
{
	const double max_dist = 2.5;
	const double max_offset = 0.5;

	t_door *nearest = NULL;
	double best_dot = -1.0;

	for (int i = 0; i < doors->len; i++)
	{
		t_door *door = &doors->doors[i];
		if (door->is_open)
			continue ;

		double dx = (door->x + 0.5) - player->pos.x;
		double dy = (door->y + 0.5) - player->pos.y;
		double dist = sqrt(dx * dx + dy * dy);
		if (dist > max_dist)
			continue ;

		double door_vec_x = dx / dist;
		double door_vec_y = dy / dist;

		// Вектор перпендикулярний до погляду
		double perp_x = -player->dir.y;
		double perp_y = player->dir.x;

		// Відстань до площини погляду (перпендикулярно)
		double offset = fabs(perp_x * dx + perp_y * dy);
		if (offset > max_offset)
			continue;

		// Скалярний добуток для перевірки чи перед нами
		double dot = door_vec_x * player->dir.x + door_vec_y * player->dir.y;
		if (dot > best_dot)
		{
			best_dot = dot;
			nearest = door;
		}
	}
	return nearest;
}


void	handle_door_interaction(t_camera *player, t_door *door,
	bool *opening_door)
{
	if (!*opening_door)
		return ;
	if (door)
	{
		door->ready_to_open = true;
		door->timer = 0.0;
	}
	*opening_door = false;
}


void	update_doors(t_doors *doors, t_map **map,
		t_camera *player, double dt)
{
	const double	door_speed = 0.009;

	for (int i = 0; i < doors->len; i++)
	{
		t_door *door = &doors->doors[i];

		if (door->ready_to_open && !door->is_open)
		{
			door->animation += dt * door_speed;  // наприклад, до 1.0
			if (door->animation >= 1.0)
			{
				door->animation = 1.0;
				door->is_open = true;
				door->ready_to_open = false;
				door->timer = 0.0;
				(*map)->matrix[door->y][door->x] = '0';
			#if DEBUG
				print_door(door, "opened");
			#endif
			}
		}
		else if (door->is_open)
		{
			if ((int)player->pos.x != door->x || (int)player->pos.y != door->y)
			{
				door->timer += dt * ((door_speed + door_speed) / 5);
				if (door->timer >= 1.0)
				{
					door->animation -= dt * door_speed; 
					(*map)->matrix[door->y][door->x] = 'd';
					if (door->animation <= 0.0)
					{
						door->is_open = false;
						door->animation = 0.0;
						door->timer = 0.0;
					}
				#if DEBUG
					print_door(door, "closed");
				#endif
				}
			}
		}
	}
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

