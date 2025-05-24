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
#include "render.h"
#include <math.h>

int	engine_loop(t_engine *eng)
{
	update_movements(&eng->camera, &eng->input);
	draw_walls(eng, &eng->ray);
	buffer_flash(&eng->main_buffer, &eng->window, 0, 0);
	usleep(100);
	return (0);
}
