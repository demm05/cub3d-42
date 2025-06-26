/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:35:40 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/24 16:35:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	parse_texture(void *mlx_ptr,
	t_textures *textures, t_raw_textrure *rt)
{
	int	i;

	i = 0;
	while (textures->tp.tex_names[i])
	{
		if (textures->tp.textures_arr[i]->img)
		{
			i++;
			continue ;
		}
		if (ft_strcmp(rt->name, textures->tp.tex_names[i]) == 0)
		{
			if (xpm_image_init(mlx_ptr, rt->path,
					textures->tp.textures_arr[i]) == -1)
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}
