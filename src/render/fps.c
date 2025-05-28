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

static inline char	*int_to_static_s(unsigned int num)
{
	static char		s[11];
	unsigned int	temp;
	int				len;

	len = 1;
	temp = num;
	while (temp > 9)
	{
		len++;
		temp /= 10;
	}
	s[len--] = 0;
	while (len >= 0)
	{
		s[len--] = num % 10 + '0';
		num /= 10;
	}
	return (s);
}

void	draw_fps_counter(t_timing *tm, t_window *win)
{
	static int	last_fps;
	static char	*s = "0";

	if (last_fps != tm->current_fps)
	{
		last_fps = tm->current_fps;
		s = int_to_static_s(last_fps);
	}
	mlx_string_put(win->mlx, win->win, 10, 10, 0x000000, s);
	if (tm->frame_start - tm->last_frame_time_us < 1000000)
		return ;
	tm->last_frame_time_us = tm->frame_start;
	tm->current_fps = tm->frame_count;
	tm->frame_count = 0;
}
