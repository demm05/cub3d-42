/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:12 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/28 17:05:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_private.h"

int	input_focus_in(t_engine *eng)
{
	(void)eng;
#if DEBUG
	printf("Focus change: in\n");
#endif
	// if (eng->state == PLAYING)
	// 	mlx_mouse_hide(eng->mlx, eng->window.win);
	return (0);
}

int	input_focus_out(t_engine *eng)
{
#if DEBUG
	printf("Focus change: out\n");
#endif
	ft_bzero(&eng->input, sizeof(t_input));
	return (0);
}

