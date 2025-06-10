/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:23:06 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/10 13:59:57 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	init_sprites_arr(t_sprite **sprites, t_textures *textures, bool mode)
{
	int	i;

	i = 0;
	if (_SPRITE_COUNT < 3)
		return (-1);
	sprites[_E_DOOR] = &textures->door;
	sprites[_E_WALLS] = &textures->walls;
	sprites[_E_NULL] = NULL;
	while (sprites[i] && mode)
		sprites[i++]->img_arr = NULL;
	return (0);
}

int	init_sprites_dir_arr(char **dir_path)
{
	if (_SPRITE_COUNT < 3)
		return (-1);
	dir_path[_E_DOOR] = _DOOR_DIR_PATH;
	dir_path[_E_WALLS] = _WALLS_DIR_PATH;
	dir_path[_E_NULL] = NULL;
	return (0);
}

int	init_texture_arr(t_image **textures_arr, t_textures *textures, bool mode)
{
	int	i;

	i = 0;
	if (_TEXTURE_COUNT < 5)
		return (-1);
	textures_arr[_E_CEILING] = &textures->ceiling;
	textures_arr[_E_FLOOR] = &textures->floor;
	textures_arr[_E_PORTAL_IN] = &textures->portal_in;
	textures_arr[_E_PORTAL_OUT] = &textures->portal_out;
	textures_arr[_E_NULL_T] = NULL;
	while (textures_arr[i] && mode)
		textures_arr[i++]->img = NULL;
	return (0);
}

int	init_texture_path_arr(char **textures_path)
{
	if (_TEXTURE_COUNT < 5)
		return (-1);
	textures_path[_E_CEILING] = _CEILING_PATH;
	textures_path[_E_FLOOR] = _FLOOR_PATH;
	textures_path[_E_PORTAL_IN] = _PORTAL_IN_PATH;
	textures_path[_E_PORTAL_OUT] = _PORTAL_OUT_PATH;
	textures_path[_E_NULL_T] = NULL;
	return (0);
}
