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
#include "mlx.h"

static inline void	update_movements(t_player *player, t_window *win)
{
	double move_amount;

	move_amount = player->speed * win->timing.delta;
	if (player->moving_up && player->y > 0)
		player->y -= move_amount;
	if (player->moving_down && player->y < win->height - PLAYER_2D_SIZE)
		player->y += move_amount;
	if (player->moving_left && player->x > 0)
		player->x -= move_amount;
	if (player->moving_right && player->x < win->width - PLAYER_2D_SIZE)
		player->x += move_amount;

	if (player->y < 0)
		player->y = 0;
	if (player->y > (double)win->height - PLAYER_2D_SIZE)
		player->y = (double)win->height - PLAYER_2D_SIZE;
	if (player->x < 0)
		player->x = 0;
	if (player->x > (double)win->width - PLAYER_2D_SIZE)
		player->x = (double)win->width - PLAYER_2D_SIZE;
}

static inline void	draw_player(t_window *window, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	while (x < PLAYER_2D_SIZE && player->x + (double)x < (double)window->width)
	{
		y = 0;
		while (y < PLAYER_2D_SIZE && player->y + (double)y < (double)window->height)
		{
			win_pixel_put(window, player->x + x, y + player->y, 0xFFDDFF);
			y++;
		}
		x++;
	}
}

int	game_loop(t_cube *cube)
{
	set_delta(&cube->window);
	win_clear_buffer(cube->mlx, &cube->window);
	update_movements(&cube->player, &cube->window);
	draw_player(&cube->window, &cube->player);
	fps_win_tick(&cube->window);
	win_flash_buffer(cube->mlx, &cube->window);
	usleep(500);
	return (0);
}
