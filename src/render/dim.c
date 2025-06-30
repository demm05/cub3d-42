/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 11:36:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

inline void	render_dimmed_screen(t_engine *eng, unsigned char dim)
{
	unsigned int	*pixel_addr;
	int				x;
	int				y;

	y = -1;
	while (++y < eng->window.height)
	{
		x = -1;
		pixel_addr = (unsigned int *)(eng->main_buffer.buffer + y * eng->main_buffer.line_size);
		while (++x < eng->window.width)
			pixel_addr[x] = blend_brightness(pixel_addr[x], dim);
	}
}
