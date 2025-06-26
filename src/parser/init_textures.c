/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:46:52 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/24 16:47:08 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	init_textures(void *mlx_ptr, t_textures *textures, t_list **lst)
{
	if (!textures || !mlx_ptr || !lst)
		return (-1);
	ft_bzero(textures, sizeof(t_textures));
	if (parse_textures(mlx_ptr, textures, lst) == -1)
	{
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": textures not found\n");
		return (-1);
	}
	return (0);
}
