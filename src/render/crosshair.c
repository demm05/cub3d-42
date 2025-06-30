/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:53:17 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 13:53:18 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

MAYBE_INLINE void	render_crosshair(t_engine *eng)
{
	t_point	start;
	int		size;

	size = 3;
	start.x = (eng->window.width - size) >> 1;
	start.y = (eng->window.height - size) >> 1;
	draw_rectangle(eng, start, (t_point){size, size}, 0xfafafa);
}
