/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:37:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 16:54:32 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_private.h"

static bool	set_pos(t_camera *cam, int d)
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
	int			y;

	cam = &eng->camera;
	x = eng->map->player_pos.x;
	y = eng->map->player_pos.y;
	cam->pos.x = x + 0.5;
	cam->pos.y = y + 0.5;
	return (set_pos(cam, eng->map->player_dir));
}
