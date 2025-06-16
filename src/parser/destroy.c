/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:50:24 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/16 12:54:57 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

/**
 * textures_arr   - single textures
 * sprites - sprite textures
 */
void	destroy_textures(void *mlx_ptr, t_textures *textures)
{
	int			i;
	int			j;

	i = 0;
	while (textures->tp.textures_arr[i] && textures->tp.textures_arr[i]->img)
		buffer_destroy(mlx_ptr, textures->tp.textures_arr[i++]);
	i = 0;
	while (textures->tp.sprites[i] && textures->tp.sprites[i]->img_arr)
	{
		j = 0;
		while (j < textures->tp.sprites[i]->len)
		{
			buffer_destroy(mlx_ptr, &textures->tp.sprites[i]->img_arr[j]);
			free(&textures->tp.sprites[i]->img_arr[j].path);
			j++;
		}
		free(textures->tp.sprites[i]->img_arr);
		i++;
	}
}

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		free_str_arr(map->matrix);
	map->matrix = NULL;
	free(map);
}
