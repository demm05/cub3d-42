/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:45:24 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/28 16:29:47 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

static bool	check_path(const char *path)
{
	char	*str;

	if (!path)
	{
		ft_putendl_fd(RED "Error" RESET ": Path is NULL", STDERR_FILENO);
		return (0);
	}
	str = ft_strchr(path, '.');
	printf("extension: %s\n", str);
	if (str && !ft_strcmp(str, ".cub"))
		return (1);
	ft_putendl_fd(RED "Error" RESET
		": Invalid file extension. Expected '.cup' file", STDERR_FILENO);
	return (0);
}

static void	set_default_values(t_world *world)
{
	if (!world)
		return ;
	ft_memset(world, 0, sizeof(t_world));
	set_default_img_values(&world->ea);
	set_default_img_values(&world->we);
	set_default_img_values(&world->so);
	set_default_img_values(&world->no);
	world->c = -1;
	world->f = -1;
	world->map = NULL;
}

int	init_world(void *mlx_ptr, t_world *world, const char *path)
{
	t_list	*lst;

	if (!world || !path || !check_path(path))
		return (-1);
	set_default_values(world);
	lst = read_file(path);
	if (!lst)
		return (-1);
	if (parse_textures(mlx_ptr, world, &lst) == -1)
	{
		ft_lstclear(&lst, t_str_free);
		return (-1);
	}
	world->map = init_map(lst);
	ft_lstclear(&lst, t_str_free);
	if (!world->map)
		return (world_destroy(mlx_ptr, world), -1);
	if (!check_world(world))
		return (world_destroy(mlx_ptr, world), -1);
	return (0);
}
