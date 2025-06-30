/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:15:33 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/30 13:48:23 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

static bool	check_sprites(t_sprite **sprites, char **sp_names)
{
	int	i;

	i = 0;
	while (i < _SPRITE_COUNT - 1)
	{
		if (!sprites[i]->img_arr)
		{
			ft_fprintf(STDERR_FILENO, RED "Error" RESET
				": sprite [%s] not found\n", sp_names[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	check_single_textures(t_image **textures_arr, char **tex_names)
{
	int	i;

	i = 0;
	while (i < _TEXTURE_COUNT - 1)
	{
		if (!textures_arr[i]->img)
		{
			ft_fprintf(STDERR_FILENO, RED "Error" RESET
				": texture [%s] not found\n", tex_names[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

int	check_textures(t_textures *textures)
{
	if (!check_single_textures(textures->tp.textures_arr,
			textures->tp.tex_names)
		|| !check_sprites(textures->tp.sprites, textures->tp.sp_names))
		return (-1);
	return (0);
}
