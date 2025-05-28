/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:45:24 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/27 12:17:37 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

static inline int	wrapper(void *mlx, t_world *world, t_list **lst)
{
	if (parse_textures(mlx, world, lst) == -1)
		return (-1);
	if (init_map(&world->map, *lst) == -1)
		return (-1);
	return (0);
}

int	world_init(void *mlx_ptr, t_world *world, const char *path)
{
	t_list	*lst;
	int		status;

	if (!mlx_ptr || !world || !path)
		return (-1);
	lst = read_file(path);
	if (!lst)
		return (-1);
	status = wrapper(mlx_ptr, world, &lst);
	ft_lstclear(&lst, t_str_free);
	return (status);
}
