/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:28:23 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/13 16:33:26 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
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

static int	add_node(t_list **lst, t_list *new, t_string *new_str)
{
	if (!new || !new_str)
	{
		ft_putendl_fd(RED "Error" RESET
			": fail to allocate memory", STDERR_FILENO);
		if (!new)
			free(new_str);
		ft_lstdelone(new, free);
		return (-1);
	}
	if (!lst)
		*lst = new;
	else
		ft_lstadd_back(lst, new);
	return (0);
}

t_list	*read_file(const char *path)
{
	t_list		*lst;
	t_list		*new;
	t_string	*new_str;
	char		*str;
	int			fd;

	if (!path)
		return (NULL);
	lst = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_line_without_endl(fd);
	while (str)
	{
		new_str = t_str_init(str);
		new = ft_lstnew(new_str);
		if (add_node(&lst, new, new_str) == -1)
			return (ft_lstclear(&lst, t_str_free), NULL);
		free(str);
		str = get_line_without_endl(fd);
	}
	close(fd);
	return (lst);
}
