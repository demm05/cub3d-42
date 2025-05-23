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

typedef struct s_frame_buf
{
	void	*mlx;	// Pointer to mlx instance
	void	*img;
	char	*buffer;
	int		depth;
	int		line_size;
	int		endian;
}	t_frame_buf;

bool    buffer_create(void *mlx, t_frame_buf *buf, int width, int height);
void	buffer_destroy(void *mlx, t_frame_buf *buf);

#endif