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

static inline void	update_movements(t_player *player, t_window *win)
{
	if (player->moving_up && player->y > 0)
		player->y -= 1;
	else if (player->moving_down && player->y < win->height - PLAYER_2D_SIZE)
		player->y += 1;
	if (player->moving_left && player->x > 0)
		player->x -= 1;
	else if (player->moving_right && player->x < win->width - PLAYER_2D_SIZE)
		player->x += 1;
}

static inline void	draw_player(t_window *window, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	while (x < PLAYER_2D_SIZE && player->x + x < window->width)
	{
		y = 0;
		while (y < PLAYER_2D_SIZE && player->y + y < window->height)
		{
			win_pixel_put(window, player->x + x, y + player->y, 0xFFDDFF);
			y++;
		}
		x++;
	}
}

int	game_loop(t_cube *cube)
{
	win_clear_buffer(cube->mlx, &cube->window);
	update_movements(&cube->player, &cube->window);
	draw_player(&cube->window, &cube->player);
	fps_win_tick(&cube->window);
	win_flash_buffer(cube->mlx, &cube->window);
	return (0);
}
