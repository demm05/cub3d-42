/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:08:48 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/10 12:19:47 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "errno.h"

static int	add_file(struct dirent *directory,
	t_list **lst, const char *dir_path)
{
	t_list	*new;
	char	*coppy;

	if (!lst || !directory)
		return (-1);
	if (check_file_ext(directory->d_name, ".xpm", 0))
	{
		coppy = ft_strjoin(dir_path, directory->d_name);
		new = ft_lstnew(coppy);
		if (!coppy || !new)
		{
			ft_putendl_fd(RED "Error" RESET
				": fail to allocate memory", STDERR_FILENO);
			if (!new)
				free(coppy);
			ft_lstdelone(new, free);
			return (-1);
		}
		if (!*lst)
			*lst = new;
		else
			ft_lstadd_back(lst, new);
	}
	return (0);
}

t_list	*readdirectory(DIR *dir, const char *path)
{
	struct dirent	*directory;
	t_list			*lst;

	lst = NULL;
	errno = 0;
	directory = readdir(dir);
	while (directory)
	{
		if (add_file(directory, &lst, path) == -1)
			return (ft_lstclear(&lst, free), NULL);
		directory = readdir(dir);
	}
	if (!lst)
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": cannot parse texture from \"%s\"\n", path);
	if (errno != 0)
	{
		ft_fprintf(STDERR_FILENO, RED "Error" RESET
			": error reading directory: %s\n", path);
		return (ft_lstclear(&lst, free), NULL);
	}
	sort_str_lst(&lst);
	return (lst);
}

char	**get_names(t_list *lst)
{
	char	**names;
	int		size;
	int		i;

	if (!lst)
		return (NULL);
	i = 0;
	size = ft_lstsize(lst);
	names = (char **)malloc(sizeof(char *) * (size + 1));
	if (!names)
		return (NULL);
	while (i < size)
	{
		names[i] = ft_strdup(lst->content);
		if (!names[i])
			return (free_str_arr(names), NULL);
		lst = lst->next;
		i++;
	}
	names[i] = NULL;
	return (names);
}
