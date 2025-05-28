/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:22:42 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/28 16:10:28 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

static bool	check_texture(t_image *img, char *texture)
{
	if (!img || !texture)
		return (0);
	if (!img->img)
	{
		ft_putstr_fd(RED "Error" RESET ": Texture ", STDERR_FILENO);
		ft_putstr_fd(texture, STDERR_FILENO);
		ft_putendl_fd(" not found", STDERR_FILENO);
		return (0);
	}
	return (1);
}

bool	check_world(t_world *world)
{
	if (!world)
		return (false);
	if (world->c == -1 || world->f == -1)
	{
		ft_putstr_fd(RED "Error" RESET ": Color not found\n", STDERR_FILENO);
		return (0);
	}
	if (!world->map)
	{
		ft_putstr_fd(RED "Error" RESET ": Map not found\n", STDERR_FILENO);
		return (0);
	}
	if (!check_texture(&world->ea, "EA") || !check_texture(&world->we, "WE")
		|| !check_texture(&world->so, "SO") || !check_texture(&world->no, "NO"))
		return (0);
	return (1);
}
