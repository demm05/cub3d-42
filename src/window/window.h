/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "cube.h"

// This function creates a window and start's a loop
void	mlx_start_loop(t_cube *cube);

// This function stop's the loop of the window and memory of 
// mlx_data is freed automatically
int		mlx_stop_loop(void *mlx);

void	mlx_enable_window_resize(void *mlx, t_window *window);

void	win_pixel_put(t_window *win, int x, int y, int color);
void	win_clear_buffer(void *mlx, t_window *win);
void	win_flash_buffer(void *mlx, t_window *win);

t_fps	*win_fps_init(void);
void	fps_win_tick(t_window *win);
void	win_fps_destroy(t_window *win);
size_t	get_current_time(void);

#endif
