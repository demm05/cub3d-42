/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:30:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 17:12:29 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_private.h"

t_ui	color_vertical(t_engine *eng, int x, int y, t_ui color)
{
	t_image		*tex;
	int			tex_x;
	int			tex_y;
	t_ray		*ray;

	(void)color;
	ray = &eng->rays[x];
	if (y < ray->draw_start)
		return (eng->world.c);
	if (y >= ray->draw_end)
		return (eng->world.f);
	tex = ray->texture;
	tex_x = ray->x_on_tex;
	if (ray->line_height <= 0)
		return (get_pixel_color(tex, tex_x, 0));
	else
		tex_y = (((y * 128 - eng->window.height * 64 + ray->line_height * 64)
					* tex->height) / ray->line_height) >> 7;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	return (get_pixel_color(tex, tex_x, tex_y));
}

void	render(t_engine *eng)
{
	int	w;
	int	h;
	int	x;

	h = eng->window.height;
	w = eng->window.width;
	x = -1;
	while (++x < w)
		cast_ray(eng, &eng->rays[x], h, w);
	draw_for_each_pixel(eng, (t_point){w, h}, color_vertical);
}
