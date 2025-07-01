/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:57:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/28 15:16:46 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cube.h"

typedef struct s_window	t_window;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_image
{
	void	*mlx;	// Pointer to mlx instance
	void	*img;
	char	*buffer;
	int		depth;
	int		line_size;
	int		width;
	int		height;
	int		endian;
	int		depth8;
}	t_image;

typedef struct s_image	t_frame_buf;

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

void	draw_fps_counter(t_timing *tm, t_window *win);

t_image	*xpm_new_image(void *mlx_ptr, char *path);
int		xpm_image_init(void *mlx_ptr, char *path, t_image *img);

void	set_default_img_values(t_image *img);

void	destroy_image(t_image *img);
void	buffer_destroy(void *mlx, t_image *buf);
bool	buffer_create(void *mlx, t_image *buf, int width, int height);

int		get_pixel_color(t_image *img, int x, int y);
t_ui	*get_pixel_address(t_image *img, int x, int y);
void	draw_vert_line(t_frame_buf *buf, t_point p, int end, int color);
void	draw_rectangle(t_engine *eng, t_point start, t_point size, t_ui color);
void	draw_pixel(t_frame_buf *buf, int x, int y, int color);

void	draw_for_each_pixel(t_engine *eng, t_point end,
			t_ui foo(t_engine *eng, int x, int y, t_ui color));
void	draw_from_to_each(t_engine *eng, t_point start, t_point size,
			t_ui foo(t_engine *eng, int x, int y, t_ui color));
void	display_fps_counter(t_timing *tm, t_engine *eng);

#endif
