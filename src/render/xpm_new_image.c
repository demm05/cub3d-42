/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:41:48 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/01 13:06:40 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

int	xpm_image_init(void *mlx_ptr, char *path, t_image *img)
{
	if (!img || !path)
		return (-1);
	if (img->img)
		return (0);
	img->mlx = mlx_ptr;
	img->img = mlx_xpm_file_to_image(mlx_ptr, path, &img->width, &img->height);
	if (!img->img)
		return (error_log("failed to open file: %s\n", path), -1);
	img->buffer = mlx_get_data_addr(img->img, &img->depth,
			&img->line_size, &img->endian);
	img->depth8 = img->depth / 8;
	return (0);
}

t_image	*xpm_new_image(void *mlx_ptr, char *path)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	if (xpm_image_init(mlx_ptr, path, img) == -1)
	{
		free(img);
		return (NULL);
	}
	return (img);
}
