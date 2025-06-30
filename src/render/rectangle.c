/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:30:05 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

MAYBE_INLINE void	draw_rectangle(t_engine *eng, t_point start, t_point size, unsigned int color)
{
	unsigned int	*pixel_addr;
	int				x;
	int				y;

	y = -1;
	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
		start.y = y;
	if (start.x + size.x > eng->main_buffer.width)
		size.x = start.x + size.x - eng->main_buffer.width;
	if (start.y + size.y > eng->main_buffer.height)
		size.y = start.y + size.y - eng->main_buffer.height;
	while (++y < size.y)
	{
		x = -1;
		pixel_addr = (unsigned int *)(eng->main_buffer.buffer + (y + start.y) *
			eng->main_buffer.line_size + (start.x * 4));
		while (++x < size.x)
			pixel_addr[x] = color;
	}
}

MAYBE_INLINE void	render_rectangle_blend(t_engine *eng, t_point start, t_point size, unsigned int color)
{
	unsigned int	*pixel_addr;
	int				x;
	int				y;

	y = -1;
	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
		start.y = y;
	if (start.x + size.x > eng->main_buffer.width)
		size.x = start.x + size.x - eng->main_buffer.width;
	if (start.y + size.y > eng->main_buffer.height)
		size.y = start.y + size.y - eng->main_buffer.height;
	while (++y < size.y)
	{
		x = -1;
		pixel_addr = (unsigned int *)(eng->main_buffer.buffer + (y + start.y) *
			eng->main_buffer.line_size + (start.x * 4));
		while (++x < size.x)
			pixel_addr[x] = blend_normal(pixel_addr[x], color);
	}
}
