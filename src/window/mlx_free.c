/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "window_private.h"

void	mlx_free(t_mlx_data **arg)
{
	t_mlx_data	*data;

	if (!arg || !*arg)
		return ;
	data = *arg;
	if (data->mlx)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->img.img)
			mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	*arg = NULL;
}
