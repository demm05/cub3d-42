/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files_from_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:46:28 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/24 15:46:45 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

char	**get_files_from_dir(const char *dir_path, const char *ext)
{
	DIR				*dir;
	t_list			*lst;
	char			**names;

	dir = opendir(dir_path);
	if (!dir)
	{
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": cannot access to directory with path: %s\n", dir_path);
		return (NULL);
	}
	lst = readdirectory(dir, dir_path, ext);
	closedir(dir);
	if (!lst)
	{
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": %s is empty\n", dir_path);
		return (NULL);
	}
	names = get_names(lst);
	ft_lstclear(&lst, free);
	if (!names)
		return (NULL);
	return (names);
}
