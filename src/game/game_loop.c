/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:15:35 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/16 16:15:55 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_private.h"

MAYBE_INLINE void win_draw_rectangle(t_window *win, int x_start, int x_size, int y_start, int y_size, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < y_size)
	{
		x = -1;
		while (++x < x_size)
		{
			win_pixel_put(win, x_start + x, y_start + y, color);
		}
	}
}

MAYBE_INLINE void draw_map(t_window *win, t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
			if (map->arr[y * map->rows + x] > 0)
				win_draw_rectangle(win, x * map->wall_width, map->wall_width - 2, y * map->wall_height, map->wall_height - 2, 0xFFFF00);
			else
				win_draw_rectangle(win, x * map->wall_width, map->wall_width, y * map->wall_height, map->wall_height, 0x000000);
		}
	}
}

int	game_loop(t_cube *cube)
{
	set_delta(&cube->window);
	win_clear_buffer(cube->mlx, &cube->window);
	update_movements(&cube->player, &cube->window);
	draw_map(&cube->window, &cube->map);
	draw_player(&cube->window, &cube->player);
	fps_win_tick(&cube->window);
	win_flash_buffer(cube->mlx, &cube->window);
	usleep(500);
	return (0);
}
