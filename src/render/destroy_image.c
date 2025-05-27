/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:59:15 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/24 13:02:05 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

void	destroy_image(t_image *img)
{
	if (!img)
		return ;
	// if (img->buffer)
	// 	free(img->buffer);
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	free(img);
}
