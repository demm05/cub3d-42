/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:15:54 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/01 12:51:55 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

static int	assigne_texture(void *mlx_ptr, t_world *world,
	const char *path, const char *tex_name)
{
	if (!ft_strcmp(tex_name, "NO"))
		return (xpm_image_init(mlx_ptr, (char *)path, &world->no));
	else if (!ft_strcmp(tex_name, "SO"))
		return (xpm_image_init(mlx_ptr, (char *)path, &world->so));
	else if (!ft_strcmp(tex_name, "WE"))
		return (xpm_image_init(mlx_ptr, (char *)path, &world->we));
	else if (!ft_strcmp(tex_name, "EA"))
		return (xpm_image_init(mlx_ptr, (char *)path, &world->ea));
	else if (!ft_strcmp(tex_name, "F"))
	{
		world->f = parse_color(path);
		if (world->f == -1)
			return (-1);
		return (0);
	}
	else if (!ft_strcmp(tex_name, "C"))
	{
		world->c = parse_color(path);
		if (world->c == -1)
			return (-1);
		return (0);
	}
	return (1);
}

static int	parse_texture(void *mlx_ptr, t_world *world, t_string *str)
{
	char	*tex_name;
	char	*path;
	char	*space_ptr;
	int		space_idx;
	int		space;

	space = skip_space(str->str);
	space_ptr = ft_strchr(str->str + space, ' ');
	if (space_ptr && space_ptr[0] > '\0')
		space_idx = space_ptr - (str->str + space);
	else
		return (1);
	tex_name = ft_substr(str->str + space, 0, space_idx);
	space = skip_space(space_ptr);
	path = space_ptr + space;
	if (!tex_name || !path || path[0] == '\0')
	{
		free(tex_name);
		return (-1);
	}
	space_idx = assigne_texture(mlx_ptr, world, path, tex_name);
	free(tex_name);
	return (space_idx);
}

int	parse_textures(void *mlx_ptr, t_world *world, t_list **lst)
{
	t_string	*str;
	size_t		i;
	int			status;

	if (!mlx_ptr || !world || !lst || !*lst)
		return (ft_putendl_fd(RED "Error" RESET
				": some arguments is null", STDERR_FILENO), -1);
	str = (t_string *)(*lst)->content;
	i = 0;
	while (ft_isspace(str->str[i]))
		i++;
	if (i == str->len)
	{
		lstdell_front(lst, t_str_free);
		return (parse_textures(mlx_ptr, world, lst));
	}
	status = parse_texture(mlx_ptr, world, str);
	if (status == -1)
		return (-1);
	else if (status == 1)
		return (0);
	lstdell_front(lst, t_str_free);
	return (parse_textures(mlx_ptr, world, lst));
}
