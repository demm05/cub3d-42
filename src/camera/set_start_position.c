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
#if DEBUG
	printf("camera_set_start_pos: Camera start info: "
		"%fx%f\tplane: %fx%f\tdir: %fx%f\n",
		cam->pos.x, cam->pos.y, cam->plane.x, cam->plane.y,
		cam->dir.x, cam->dir.y);
#endif
	return (1);
}

bool	camera_set_start_pos(t_engine *eng)
{
	t_camera	*cam;
	int			x;
	int 		y;

#if DEBUG
	puts("Setting start position of camera");
#endif
	cam = &eng->camera;
	x = eng->map->player_pos.x;
	y = eng->map->player_pos.y;
	cam->pos.x = x + 0.5;
	cam->pos.y = y + 0.5;
	return (set_pos(cam, eng->map->player_dir));
}
