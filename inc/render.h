/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:57:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 11:38:02 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cube.h"

typedef struct s_window	t_window;

typedef struct s_frame_buf
{
	void	*mlx;	// Pointer to mlx instance
	void	*img;
	char	*buffer;
	int		depth;
	int		line_size;
	int		endian;
	int		width;
	int		height;
}	t_frame_buf;

typedef struct s_timing
{
	size_t	last_frame_time_us;
	size_t	frame_start;
	double	delta_time;
	int		frame_count;
	int		current_fps;
}	t_timing;

bool	buffer_create(void *mlx, t_frame_buf *buf, int width, int height);
void	buffer_destroy(void *mlx, t_frame_buf *buf);
void	buffer_flash(t_frame_buf *buf, t_window *win, int x, int y);
void	buffer_clear(t_frame_buf *buf);

void	draw_vert_line(t_frame_buf *buf, int x, int start, int end, int color);
void	draw_rectangle(t_frame_buf *buf, int x, int y,
			int width, int height, int color);
void	draw_pixel(t_frame_buf *buf, int x, int y, int color);
void	draw_fps_counter(t_timing *tm, t_window *win);

#endif
