/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:41:48 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/02 12:09:55 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

int	xpm_image_init(void *mlx_ptr, char *path, t_image *img)
{
	if (!img || !path)
		return (-1);
	img->mlx = mlx_ptr;
	img->img = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->depth, &img->line_size);
	if (!img->img)
		return (ft_fprintf(STDERR_FILENO, RED"Error" RESET ": failed to open file: %s\n", path), -1);
	img->buffer = mlx_get_data_addr(img->img, &img->depth,
			&img->line_size, &img->endian);
	img->height = IMG_HEIGHT;
	img->width = IMG_WIDTH;
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
