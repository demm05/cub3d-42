/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:21 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:03 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"
#include "sys/time.h"

static inline size_t	get_current_time_microseconds(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	eng_new_frame(t_engine *eng)
{
	t_timing	*tm;
	size_t		current_time;

	current_time = get_current_time_microseconds();
	tm = &eng->timing;
	tm->delta_time = (double)(current_time - tm->frame_start) / 1000000.0;
	tm->frame_start = current_time;
	if (tm->delta_time > MAX_DELTA_TIME)
		tm->delta_time = MAX_DELTA_TIME;
	tm->frame_count++;
	if (tm->frame_start - tm->last_frame_time_us < 1000000)
		return ;
	tm->last_frame_time_us = tm->frame_start;
	tm->current_fps = tm->frame_count;
	tm->frame_count = 0;
	eng->draw_new_frame = 1;
}
