/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:25:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/10 12:38:50 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"

void	mlx_destroy(t_engine *eng);

void	engine_destroy(t_engine *eng)
{
	if (!eng)
		return ;
	destroy_map(eng->map);
	destroy_textures(eng->mlx, &eng->textures);
	mlx_destroy(eng);
	destroy_rays(eng);
	text_destroy(eng);
	free(eng->table.y);
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
