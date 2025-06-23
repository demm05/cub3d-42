/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:08:14 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/18 13:23:08 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	parse_file(void *mlx_ptr, t_engine *eng, char *path)
{
	t_list	*lst;

	lst = read_file(path);
	if (!lst)
		return (0);
	if (init_textures(mlx_ptr, &eng->textures, &lst) == -1)
		return (ft_lstclear(&lst, t_str_free), 0);
	eng->map = init_map(lst);
	ft_lstclear(&lst, t_str_free);
	if (!eng->map)
		return (0);
	if (parse_doors(&eng->doors, eng->map) == -1)
		return (0);
	return (1);
}
