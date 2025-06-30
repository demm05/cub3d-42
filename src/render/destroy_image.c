/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:59:15 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/30 14:17:02 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

void	destroy_image(t_image *img)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	free(img);
	img = NULL;
}
