/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:15:54 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/18 12:59:36 by ogrativ          ###   ########.fr       */
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
		i++;
	}
	free_str_arr(names);
	return (0);
}

static int	init_raw_texture(t_list *lst, t_raw_textrure *tex)
{
	t_string		*str;
	char			*space_ptr;
	int				space_idx;
	int				space;

	if (!lst || !tex)
		return (-1);
	space = 0;
	ft_bzero(tex, sizeof(t_raw_textrure));
	str = (t_string *)lst->content;
	while (str->str[space] == ' ')
		space++;
	if (str->str[space] == '\n' || str->str[space] == '\0')
		return (0);
	space_ptr = ft_strchr(str->str + space, ' ');
	if (space_ptr && space_ptr[0] > '\0')
		space_idx = space_ptr - (str->str + space);
	else
		return (-2);
	tex->name = ft_substr(str->str + space, 0, space_idx);
	space = 0;
	while (space_ptr[space] == ' ')
		space++;
	tex->path = space_ptr + space;
	if (!tex->name || !tex->path || tex->path[0] == '\0')
		return (free(tex->name), -1);
	return (space_idx);
}

static int	parse_texture(void *mlx_ptr,
	t_textures *textures, t_raw_textrure *rt)
{
	int	i;

	i = 0;
#if DEBUG
	printf("rt.name: %s\n", rt->name);
#endif
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

static int	parse_sprite(void *mlx_ptr,
	t_textures *textures, t_raw_textrure *rt)
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

static void	free_rt(t_raw_textrure *rt)
{
	if (!rt)
		return ;
	free(rt->name);
	rt->name = NULL;
}

static int	parse_textures(void *mlx_ptr, t_textures *textures, t_list **lst)
{
	t_raw_textrure		rt;
	int					sprite_res;
	int					tex_res;
	int					status;

	if (init_texture_pointers(textures, 1) == -1)
		return (-1);
	ft_bzero(&rt, sizeof(t_raw_textrure));
	status = init_raw_texture(*lst, &rt);
	while (status != -1 && status != -2)
	{
		if (status == 0)
		{
			lstdell_front(lst, t_str_free);
			status = init_raw_texture(*lst, &rt);
			continue ;
		}
		sprite_res = parse_sprite(mlx_ptr, textures, &rt);
		tex_res = parse_texture(mlx_ptr, textures, &rt);
		free_rt(&rt);
		if (sprite_res == -1 || tex_res == -1)
			return (-1);
		lstdell_front(lst, t_str_free);
		status = init_raw_texture(*lst, &rt);
#if DEBUG
		printf("rt.name: %s status: %i\n", rt.name, status);
#endif
	}
	if (status == -1)
		return (-1);
	free_rt(&rt);
	return (0);
}

int	init_textures(void *mlx_ptr, t_textures *textures, t_list **lst)
{
	if (!textures || !mlx_ptr || !lst)
		return (-1);
	ft_bzero(textures, sizeof(t_textures));
	if (parse_textures(mlx_ptr, textures, lst) == -1)
	{
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": textures not found\n");
		return (-1);
	}
	return (0);
}
