/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:24:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 12:37:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"

int	engine_loop(t_engine *eng)
{
	if (eng->input.resizing)
	{
		usleep(50000);
		eng->input.resizing = 0;
		eng->draw_new_frame = 1;
		if (!update_lookup_table(eng))
			enging_loop_stop(eng);
		return (0);
	}
	eng_new_frame(eng);
	if (!eng->draw_new_frame)
		return (usleep(20000), 0);
	camera_keyboard_move_event(eng, &eng->camera);
	camera_keyboard_rotate_event(eng);
	camera_mouse_move_event(eng);
	render_frame(eng);
	buffer_flash(&eng->main_buffer, &eng->window, 0, 0);
	return (0);
}

void	enging_loop_stop(t_engine *eng)
{
	mlx_loop_end(eng->mlx);
}
