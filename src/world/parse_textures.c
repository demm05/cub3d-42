/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:15:54 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/28 16:16:18 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

bool	is_rgb(int color)
{
	if (color >= 0 && color < 256)
	{
		return (1);
	}
	return (0);
}

static int	parse_color(const char *path)
{
	char	**numbers;
	t_rgb	rgb;
	size_t	len;

	numbers = ft_split((char *)path, ",");
	if (!numbers)
		return (-1);
	len = split_len(numbers);
	if (len != 3)
	{
		free_str_arr(numbers);
		ft_putstr_fd(RED "Error" RESET
			": Incorrect RGB format\n", STDERR_FILENO);
		return (-1);
	}
	rgb.red = ft_atoi(numbers[0]);
	rgb.green = ft_atoi(numbers[1]);
	rgb.blue = ft_atoi(numbers[2]);
	free_str_arr(numbers);
	if (is_rgb(rgb.blue) && is_rgb(rgb.green) && is_rgb(rgb.red))
		return ((rgb.red << 16) | (rgb.green << 8) | rgb.blue);
	ft_putstr_fd(RED "Error" RESET
		": Incorrect RGB format: Values must be beetwen 0-255\n",
		STDERR_FILENO);
	return (-1);
}

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

	space_ptr = ft_strchr(str->str, ' ');
	if (!space_ptr)
		return (-1);
	space_idx = space_ptr - str->str;
	tex_name = ft_substr(str->str, 0, space_idx);
	path = space_ptr + 1;
	if (!tex_name || !path || path[0] == '\0')
	{
		free(tex_name);
		return (-1);
	}
	space_idx = assigne_texture(mlx_ptr, world, path, tex_name);
	printf("texture: %s   PATH: %s\n", tex_name, path);
	free(tex_name);
	return (space_idx);
}

int	parse_textures(void *mlx_ptr, t_world *world, t_list **lst)
{
	t_string	*str;
	size_t		i;
	int			status;

	if (!mlx_ptr || !world || !lst || !*lst)
		return (-1);
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
