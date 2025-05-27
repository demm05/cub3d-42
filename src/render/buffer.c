/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:32:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/24 13:08:19 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

bool	buffer_create(void *mlx, t_image *buf, int width, int height)
{
	buf->img = mlx_new_image(mlx, width, height);
	if (!buf->img)
		return (0);
	buf->buffer = mlx_get_data_addr(buf->img, &buf->depth, &buf->line_size,
			&buf->endian);
	if (!buf->buffer)
		return (0);
	buf->width = width;
	buf->height = height;
	return (1);
}

void	buffer_destroy(void *mlx, t_image *buf)
{
	if (!mlx || !buf || !buf->img)
		return ;
	mlx_destroy_image(mlx, buf->img);
}
