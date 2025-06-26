/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:15:54 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/24 17:32:17 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "errno.h"

static void	free_rt(t_raw_textrure *rt)
{
	if (!rt)
		return ;
	free(rt->name);
	rt->name = NULL;
}

static int	init_raw_texture(t_list *lst, t_raw_textrure *tex)
{
	t_string		*str;
	char			*space_ptr;
	int				space_idx;
	int				space;

	if (!lst || !tex)
		return (-1);
	ft_bzero(tex, sizeof(t_raw_textrure));
	str = (t_string *)lst->content;
	space = skip_space(str->str);
	if (str->str[space] == '\n' || str->str[space] == '\0')
		return (0);
	space_ptr = ft_strchr(str->str + space, ' ');
	if (space_ptr && space_ptr[0] > '\0')
		space_idx = space_ptr - (str->str + space);
	else
		return (-2);
	tex->name = ft_substr(str->str + space, 0, space_idx);
	space = skip_space(space_ptr);
	tex->path = space_ptr + space;
	if (!tex->name || !tex->path || tex->path[0] == '\0')
		return (free_rt(tex), -1);
	return (space_idx);
}

static int	assigne_textures(void *mlx_ptr,
	t_textures *textures, t_raw_textrure *rt)
{
	int	sprite_res;
	int	tex_res;

	sprite_res = parse_sprite(mlx_ptr, textures, rt);
	tex_res = parse_texture(mlx_ptr, textures, rt);
	free_rt(rt);
	if (sprite_res == -1 || tex_res == -1)
		return (-1);
	return (0);
}

int	parse_textures(void *mlx_ptr, t_textures *textures, t_list **lst)
{
	t_raw_textrure		rt;
	int					status;

	if (init_texture_pointers(textures, 1) == -1)
		return (-1);
	status = init_raw_texture(*lst, &rt);
	while (status != -1 && status != -2)
	{
		if (status == 0)
		{
			lstdell_front(lst, t_str_free);
			status = init_raw_texture(*lst, &rt);
			continue ;
		}
		if (assigne_textures(mlx_ptr, textures, &rt) == -1)
			return (-1);
		lstdell_front(lst, t_str_free);
		status = init_raw_texture(*lst, &rt);
	}
	free_rt(&rt);
	if (status == -1)
		return (-1);
	return (0);
}
