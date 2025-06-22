/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:04:29 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/28 17:04:29 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

void	display_fps_counter(t_timing *tm, t_engine *eng)
{
	text_put_int(eng, (t_point){2, 2}, tm->current_fps, 0xFF00FF);
	if (tm->frame_start - tm->last_frame_time_us < 1000000)
		return ;
	tm->last_frame_time_us = tm->frame_start;
	tm->current_fps = tm->frame_count;
	tm->frame_count = 0;
	eng->menu.is_drawn = 0;
}
