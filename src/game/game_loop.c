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

#include "cube.h"
#include "game_private.h"
#include "mlx.h"
#include "types.h"
#include "unistd.h"
#include <strings.h>
#include <string.h>

static inline void    update_movements(t_player *player, t_window *win)
{
    if (player->moving_up && player->y > 0)
        player->y -= 1;
    else if (player->moving_down && player->y < win->height - 101)
        player->y += 1;
    if (player->moving_left && player->x > 0)
        player->x -= 1;
    else if (player->moving_right && player->x < win->width - 101)
        player->x += 1;
}

static inline void draw_player_with_img(t_cube *cube)
{
    int x;
    int y;

	memset(cube->mlx->img.buffer, 0, cube->window.height * cube->mlx->img.line_size);
    x = 0;
    while (x < 100 && cube->player.x + x < cube->window.width)
    {
        y = 0;
        while (y < 100 && cube->player.y + y < cube->window.height)
        {
        	mlx_put_pixel(&cube->mlx->img, cube->player.x + x, y + cube->player.y, 0xFFDDFF);
        	y++;
    	}
    	x++;
    }
    mlx_put_image_to_window(cube->mlx->mlx, cube->mlx->win, cube->mlx->img.img, 0, 0);
}

static inline void draw_player_with_x11(t_cube *cube)
{
    int x;
    int y;

    mlx_clear_window(cube->mlx->mlx, cube->mlx->win);
    x = 0;
    while (x < 100 && cube->player.x + x < cube->window.width)
    {
        y = 0;
        while (y < 100 && cube->player.y + y < cube->window.height)
        {
        	mlx_pixel_put(cube->mlx->mlx, cube->mlx->win, cube->player.x + x, y + cube->player.y, 0xFFDDFF);
        	y++;
    	}
    	x++;
    }
    mlx_do_sync(cube->mlx->mlx);
}

int	game_loop(t_cube *cube)
{
    int frames;

    update_movements(&cube->player, &cube->window);
    draw_player_with_img(cube);
    // draw_player_with_x11(cube);
    if (fps_counter_tick(cube->window.fps))
    {
        frames = fps_counter_get_fps(cube->window.fps);
        printf("%d\n", frames);
    }
	return (0);
}
