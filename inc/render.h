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

# define IMG_WIDTH 32
# define IMG_HEIGHT 32

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
}	t_image;

typedef struct s_image	t_frame_buf;

bool	buffer_create(void *mlx, t_frame_buf *buf, int width, int height);
void	buffer_destroy(void *mlx, t_frame_buf *buf);
void	buffer_flash(t_frame_buf *buf, t_window *win, int x, int y);
void	buffer_clear(t_frame_buf *buf);

void	draw_vert_line(t_frame_buf *buf, int x, int start, int end, int color);
void	draw_rectangle(t_frame_buf *buf, int x, int y,
			int width, int height, int color);
void	draw_pixel(t_frame_buf *buf, int x, int y, int color);

t_image	*xpm_new_image(void *mlx_ptr, char *path);
int		xpm_image_init(void *mlx_ptr, char *path, t_image *img);

void	set_default_img_values(t_image *img);

void	destroy_image(t_image *img);
void	buffer_destroy(void *mlx, t_image *buf);
bool	buffer_create(void *mlx, t_image *buf, int width, int height);
// bool    buffer_create(void *mlx, t_frame_buf *buf, int width, int height);
// void	buffer_destroy(void *mlx, t_frame_buf *buf);

#endif
