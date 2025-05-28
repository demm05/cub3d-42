/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:28:23 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/28 14:32:26 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"
#include <sys/stat.h>
#include <fcntl.h>

static void	print_lst(t_list *lst)
{
	t_string	*str;

	while (lst)
	{
		str = (t_string *)lst->content;
		printf("%s\n", str->str);
		lst = lst->next;
	}
	printf("\n\n\n");
}

char	*get_line_without_endl(int fd)
{
	char	*str;
	char	*tmp;
	char	*newline;


	str = get_next_line(fd);
	if (!str)
		return (NULL);
	newline = ft_strrchr(str, '\n');
	if (str && newline && newline[0] == '\n')
		tmp = ft_substr(str, 0, ft_strlen(str) - 1);
	else
		tmp = ft_strdup(str);
	free(str);
	return (tmp);
}

t_list	*read_file(const char *path)
{
	t_list	*lst;
	char	*str;
	int		fd;

#if DEBUG
	printf("Reading the file: %s\n", path);
#endif
	if (!path)
		return (NULL);
	lst = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_line_without_endl(fd);
	while (str)
	{
		if (!lst)
			lst = ft_lstnew(t_str_init(str));
		else
			ft_lstadd_back(&lst, ft_lstnew(t_str_init(str)));
		free(str);
		str = get_line_without_endl(fd);
	}
	free(str);
	close(fd);
	print_lst(lst);
	return (lst);
}
