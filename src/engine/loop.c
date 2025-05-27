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
	eng_new_frame(&eng->timing);
	update_keyboard_events(&eng->camera, &eng->input, &eng->timing);
	update_mouse_event(&eng->camera, &eng->input, &eng->timing);
	draw_walls(eng, &eng->ray);
	buffer_flash(&eng->main_buffer, &eng->window, 0, 0);
	draw_fps_counter(&eng->timing, &eng->window);
	return (0);
}
