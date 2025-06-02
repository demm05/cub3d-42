/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:22:42 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/02 11:30:21 by ogrativ          ###   ########.fr       */
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

static bool	check_colors(t_world *world)
{
	int	status;

	status = 0;
	if (world->c == -1)
	{
		ft_putstr_fd(RED "Error" RESET ": Ceiling color not found\n",
			STDERR_FILENO);
		status++;
	}
	if (world->f == -1)
	{
		ft_putstr_fd(RED "Error" RESET ": Floor color not found\n",
			STDERR_FILENO);
		status++;
	}
	if (status > 0)
		return (0);
	return (1);
}

static bool	check_textures(t_world *world)
{
	int	status;

	status = 0;
	status += check_texture(&world->ea, "EA");
	status += check_texture(&world->we, "WE");
	status += check_texture(&world->so, "SO");
	status += check_texture(&world->no, "NO");
	if (status != 4)
		return (0);
	return (1);
}

bool	check_world(t_world *world)
{
	int	error_count;

	error_count = 0;
	if (!world)
		return (false);
	if (!check_colors(world))
		error_count++;
	if (!world->map)
	{
		ft_putstr_fd(RED "Error" RESET ": Map not found\n", STDERR_FILENO);
		error_count++;
	}
	if (check_textures(world) && !error_count)
		return (1);
	else
		return (0);
}
