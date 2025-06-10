/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:15:54 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/10 12:09:37 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "errno.h"

static char	**get_files_from_dir(const char *dir_path)
{
	DIR				*dir;
	t_list			*lst;
	char			**names;

	dir = opendir(dir_path);
	if (!dir)
	{
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": cannot access to directory with path: %s\n", dir_path);
		return (NULL);
	}
	lst = readdirectory(dir, dir_path);
	closedir(dir);
	if (!lst)
	{
		ft_fprintf(STDERR_FILENO, RED "Error" RESET ": directory is empty\n");
		return (NULL);
	}
	names = get_names(lst);
	ft_lstclear(&lst, free);
	if (!names)
		return (NULL);
	return (names);
}

static int	parse_sprite_from_dir(void *mlx_ptr,
	t_sprite *sprite, char *dir_path)
{
	char	**names;
	int		i;

	i = 0;
	names = get_files_from_dir(dir_path);
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
		printf("sprite path: %s\n", sprite->img_arr[i].path);
		i++;
	}
	free_str_arr(names);
	return (0);
}

static int	parse_sprites(void *mlx_ptr, t_textures *textures)
{
	t_sprite	*sprites[_SPRITE_COUNT];
	char		*directories[_SPRITE_COUNT];
	int			i;

	i = 0;
	if (init_sprites_arr(sprites, textures) == -1
		|| init_sprites_dir_arr(directories) == -1)
		return (-1);
	while (sprites[i])
	{
		if (parse_sprite_from_dir(mlx_ptr, sprites[i], directories[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

static int	parse_textures(void *mlx_ptr, t_textures *textures)
{
	t_image	*textures_arr[_TEXTURE_COUNT];
	char	*path[_TEXTURE_COUNT];
	int		i;

	if (init_texture_arr(textures_arr, textures) == -1
		|| init_texture_path_arr(path) == -1)
		return (-1);
	i = 0;
	while (i < _TEXTURE_COUNT - 1)
	{
		if (xpm_image_init(mlx_ptr, path[i], textures_arr[i]) == -1)
		{
			destroy_textures(mlx_ptr, textures);
			return (-1);
		}
		printf("texture path: %s\n", textures_arr[i]->path);
		i++;
	}
	if (parse_sprites(mlx_ptr, textures) == -1)
	{
		destroy_textures(mlx_ptr, textures);
		return (-1);
	}
	return (0);
}

int	init_textures(void *mlx_ptr, t_textures *textures)
{
	if (!textures || !mlx_ptr)
		return (-1);
	return (parse_textures(mlx_ptr, textures));
}
