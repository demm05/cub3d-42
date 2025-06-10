/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:50:24 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/10 14:02:35 by ogrativ          ###   ########.fr       */
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
	t_image		*textures_arr[_TEXTURE_COUNT];
	t_sprite	*sprites[_SPRITE_COUNT];

	i = 0;
	init_texture_arr(textures_arr, textures, 0);
	init_sprites_arr(sprites, textures, 0);
	while (textures_arr[i] && textures_arr[i]->img)
		buffer_destroy(mlx_ptr, textures_arr[i++]);
	i = 0;
	while (sprites[i] && sprites[i]->img_arr)
	{
		j = 0;
		while (j < sprites[i]->len)
			buffer_destroy(mlx_ptr, &sprites[i]->img_arr[j++]);
		free(sprites[i]->img_arr);
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
