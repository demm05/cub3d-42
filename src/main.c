/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:43 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/27 14:50:44 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(void)
{
	t_engine	eng;

	if (engine_init(&eng))
		mlx_loop(eng.mlx);
	engine_destroy(&eng);
	return (0);
}

void	set_defaults(t_engine *eng)
{
	if (!eng)
		return ;
	eng->window.height = INITIAL_WINDOW_HEIGHT;
	eng->window.width = INITIAL_WINDOW_WIDTH;
	eng->window.title = WINDOW_TITLE;
	eng->camera.dir.x = -1;
	eng->camera.dir.y = 0;
	eng->camera.plane.x = 0;
	eng->camera.plane.y = 0.66;
	eng->camera.pos.x = 27;
	eng->camera.pos.y = 11;
	eng->camera.move_speed = 3;
	eng->camera.rotation_speed = 3;
}
