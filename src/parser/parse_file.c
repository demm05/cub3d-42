/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:08:14 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/16 12:19:36 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	parse_file(void *mlx_ptr, t_textures *textures, t_map *map, char *path)
{
	t_list	*lst;

	lst = read_file(path);
	if (!lst)
		return (0);
	if (init_textures(mlx_ptr, textures, &lst) == -1)
	{
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": textures not found\n");
		ft_lstclear(&lst, t_str_free);
		return (0);
	}
	map = init_map(lst);
	ft_lstclear(&lst, t_str_free);
	if (!map)
		return (0);
	return (1);
}
