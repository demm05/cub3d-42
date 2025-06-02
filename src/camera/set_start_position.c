/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:37:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/02 13:37:48 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"

static inline bool	set_pos(t_camera *cam, int d)
{
	if (d == 'S')
	{
		cam->dir.y = 1;
		cam->plane.x = FOV;
	}
	else if (d == 'E')
	{
		cam->dir.x = 1;
		cam->plane.y = -FOV;
	}
	else if (d == 'N')
	{
		cam->plane.x = -FOV;
		cam->dir.y = -1;
	}
	else if (d == 'W')
	{
		cam->dir.x = -1;
		cam->plane.y = FOV;
	}
	else
		return (0);
	return (1);
}

bool	camera_set_start_pos(t_engine *eng)
{
	t_camera	*cam;
	int			x;
	int 		y;
	char		d;

	cam = &eng->camera;
	x = eng->world.map->player_pos.x;
	y = eng->world.map->player_pos.y;
	cam->pos.x = x;
	cam->pos.y = y;
	d = map_get(&eng->world, x, y);
	map_set(&eng->world, x, y, '0');
	return (set_pos(cam, d));
}
