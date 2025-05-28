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

bool	init_world(void *mlx_ptr, t_world *world, const char *path)
{
	t_list	*lst;

	if (!world || !path)
		return (0);
	lst = read_file(path);
	if (!lst)
		return (0);
	#if DEBUG
	printf("\nparse_textures\n");
	#endif
	if (parse_textures(mlx_ptr, world, &lst) == -1)
	{
		ft_lstclear(&lst, t_str_free);
		return (0);
	}
	#if DEBUG
	printf("\ninit_map start\n");
	#endif
	if (!init_map(&world->map, lst))
	{
		ft_lstclear(&lst, t_str_free);
		return (0);
	}
	ft_lstclear(&lst, t_str_free);
	#if DEBUG
	printf("\ninit_map end\n");
	#endif
	return (1);
}
