/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:32:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 12:45:02 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

bool    buffer_create(void *mlx, t_frame_buf *buf, int width, int height)
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
# if DEBUG
	printf("New buffer was created: w:%d\th:%d\td:%d\tl:%d\n", width, height, buf->depth, buf->line_size);
#endif
    return (1);
}

void	buffer_destroy(void *mlx, t_frame_buf *buf)
{
	if (!mlx || !buf || !buf->img)
		return ;
	mlx_destroy_image(mlx, buf->img);
}
