/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:44:52 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/24 16:45:32 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

static int	parse_sprite_from_dir(void *mlx_ptr,
	t_sprite *sprite, char *dir_path)
{
	char	**names;
	int		i;

	i = 0;
	names = get_files_from_dir(dir_path, ".xpm");
	if (!names)
		return (-1);
	sprite->len = split_len(names);
	sprite->img_arr = ft_calloc(sizeof(t_image), sprite->len);
	if (!sprite->img_arr)
		return (free_str_arr(names), -1);
	while (i < sprite->len)
	{
		if (xpm_image_init(mlx_ptr, names[i], &sprite->img_arr[i]) == -1)
			return (free_str_arr(names), -1);
		i++;
	}
	free_str_arr(names);
	return (0);
}

int	parse_sprite(void *mlx_ptr, t_textures *textures, t_raw_textrure *rt)
{
	int	i;

	i = 0;
	while (textures->tp.sp_names[i])
	{
		if (ft_strcmp(rt->name, textures->tp.sp_names[i]) == 0)
		{
			if (textures->tp.sprites[i]->img_arr)
			{
				i++;
				continue ;
			}
			if (parse_sprite_from_dir(mlx_ptr,
					textures->tp.sprites[i], rt->path) == -1)
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}
