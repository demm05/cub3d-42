/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:25:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 12:38:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"

void	mlx_destroy(t_engine *eng);

void	engine_destroy(t_engine *eng)
{
	if (!eng)
		return ;
	world_destroy(eng->mlx, &eng->world);
	mlx_destroy(eng);
	destroy_rays(eng);
}

void	mlx_destroy(t_engine *eng)
{
	if (!eng->mlx)
		return ;
	if (DISABLE_AUTOREPEAT_KEY)
		mlx_do_key_autorepeaton(eng->mlx);
	if (eng->window.win)
		mlx_destroy_window(eng->mlx, eng->window.win);
	buffer_destroy(eng->mlx, &eng->main_buffer);
	mlx_destroy_display(eng->mlx);
	free(eng->mlx);
}
