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
	eng->input.prev_mouse_pos.x = eng->window.width >> 1;
	eng->input.prev_mouse_pos.y = eng->window.height >> 1;
	mlx_mouse_hide(eng->mlx, eng->window.win);
	return (0);
}

int	input_focus_out(t_engine *eng)
{
	bool	minimap_toggle;

#if DEBUG
	printf("Focus change: out\n");
#endif
	minimap_toggle = eng->input.minimap_toggle;
	ft_bzero(&eng->input, sizeof(t_input));
	eng->input.minimap_toggle = minimap_toggle;
	return (0);
}

