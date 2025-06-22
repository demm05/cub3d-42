/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:57:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/16 14:56:23 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cube.h"

typedef struct s_window	t_window;

typedef struct s_rgb
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
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

void	buffer_destroy(void *mlx, t_image *buf);
bool	buffer_create(void *mlx, t_image *buf, int width, int height);
void	buffer_flash(t_frame_buf *buf, t_window *win, int x, int y);
void	buffer_clear(t_frame_buf *buf);


t_image	*xpm_new_image(void *mlx_ptr, char *path);
int		xpm_image_init(void *mlx_ptr, char *path, t_image *img);

void	destroy_image(t_image *img);

// DRAWING
int		get_pixel_color(t_image *img, int x, int y);
t_ui	*get_pixel_address(t_image *img, int x, int y);
void	draw_vert_line(t_frame_buf *buf, int x, int start, int end, int color);
void	draw_rectangle(t_engine *eng, t_point start, t_point size, unsigned int color);
void	draw_pixel(t_frame_buf *buf, int x, int y, int color);

void	draw_for_each_pixel(t_engine *eng, t_point end,
				unsigned int foo(t_engine *eng, int x, int y, unsigned int color));
void	draw_from_to_each(t_engine *eng, t_point start, t_point size,
				unsigned int foo(t_engine *eng, int x, int y, unsigned int color));
void	display_fps_counter(t_timing *tm, t_engine *eng);
// DRAWING

t_ui	blend_normal(t_ui source, t_ui dest);

void	render_frame(t_engine *eng);
t_ui	blend_brightness(t_ui color, float br);
void	blend_normal_a(t_engine *eng, t_point p, t_ui dest, unsigned char alpha);

void	render_minimap(t_engine *eng);

#endif
