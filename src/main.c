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

int	main(int argc, char **argv)
{
	t_engine	eng;

	if (argc < 2)
		return (ft_fprintf(2, RED"Error"RESET": Please provide map\n"));
	if (argc > 2)
		return (ft_fprintf(2, RED"Error"RESET": Too many arguments\n"));
	if (engine_init(&eng, argv[1]))
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
	eng->camera.move_speed = 3;
	eng->camera.rotation_speed = 2;
	eng->camera.mouse_speed = 0.2;
	eng->state = MENU;
	eng->draw_new_frame = 1;
}
