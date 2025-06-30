/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:17:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 15:17:07 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

static inline void	weapon_loop(t_engine *eng, t_image *texture,
	t_point scaled_size, t_point screen_pos)
{
	t_point	tex;
	t_ui	color;
	int		x;
	int		y;

	y = -1;
	while (++y < scaled_size.y)
	{
		x = -1;
		while (++x < scaled_size.x)
		{
			tex.x = (int)((double)x / scaled_size.x * texture->width);
			tex.y = (int)((double)y / scaled_size.y * texture->height);
			color = get_pixel_color(texture, tex.x, tex.y);
			if (!((color >> 24) & 0xFF))
				draw_pixel(&eng->main_buffer, screen_pos.x + x,
					screen_pos.y + y, color);
		}
	}
}

inline void	render_weapon(t_engine *eng)
{
	t_image	*texture;
	t_point	scaled_size;
	t_point	screen_pos;

	texture = animation_get_image(eng->player.weapon);
	if (!texture || !texture->img)
		return ;
	scaled_size.x = eng->window.width * 0.2;
	scaled_size.y = (int)((double)scaled_size.x * \
		((double)texture->height / texture->width));
	screen_pos.x = (eng->window.width - scaled_size.x) / 2;
	screen_pos.y = eng->window.height - scaled_size.y;
	weapon_loop(eng, texture, scaled_size, screen_pos);
}
