/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:41:48 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/09 17:02:29 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

static void	print_err(char *path)
{
	ft_putstr_fd(RED "Error" RESET ": faild to open file ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	set_default_img_values(t_image *img)
{
	if (!img)
		return ;
	img->buffer = NULL;
	img->img = NULL;
}

int	xpm_image_init(void *mlx_ptr, char *path, t_image *img)
{
	if (!img || !path)
		return (-1);
	img->mlx = mlx_ptr;
	img->img = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->depth, &img->line_size);
	if (!img->img)
	{
		print_err(path);
		return (-1);
	}
	img->buffer = mlx_get_data_addr(img->img, &img->depth,
			&img->line_size, &img->endian);
	img->path = ft_strdup(path);
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

