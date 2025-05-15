/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	mlx_put_pixel(t_mlx_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_size) + (x * (img->depth / 8));
	*((unsigned int *)(offset + img->buffer)) = color;
}
