/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:34:22 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/10 12:18:33 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

bool	check_file_ext(const char *path, const char *ext, bool mode)
{
	char	*str;

	if (!path)
	{
		ft_putendl_fd(RED "Error" RESET ": Path is NULL", STDERR_FILENO);
		return (0);
	}
	str = ft_strrchr(path, '.');
	if (str && !ft_strcmp(str, ext))
		return (1);
	if (mode == 1)
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": Invalid file extension. Expected a '%s' file.\n", ext);
	return (0);
}
