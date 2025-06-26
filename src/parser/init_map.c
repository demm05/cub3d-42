/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:37:21 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/25 13:50:16 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

static size_t	find_max_len(t_list *lst)
{
	size_t		max;
	t_string	*str;

	max = 0;
	while (lst)
	{
		str = (t_string *)lst->content;
		if (str->len > max)
			max = str->len;
		lst = lst->next;
	}
	return (max);
}

static void	fill_line(t_map *map, t_string *str, size_t j)
{
	size_t	i;

	i = 0;
	while (str->str[i] != '\0')
	{
		if (str->str[i] == '\n')
			map->matrix[j][i] = '0';
		else if (str->str[i] == ' ')
		{
		}
		else
			map->matrix[j][i] = str->str[i];
		i++;
	}
	map->matrix[j][i] = '\0';
}

static void	fill_matrix(t_map *map, t_list *lst)
{
	t_string	*str;
	int			j;

	j = 0;
	while (j < map->height)
	{
		str = (t_string *)lst->content;
		map->matrix[j] = malloc(map->width + 1);
		if (!map->matrix[j])
			return (free_str_arr(map->matrix));
		ft_memset(map->matrix[j], '0', map->width);
		fill_line(map, str, j);
		j++;
		lst = lst->next;
	}
	map->matrix[j] = NULL;
}

// static void	print_matrix(t_map *map)
// {
// 	int	i;

// 	if (!map)
// 		return ;
// 	i = -1;
// 	while (++i < map->height)
// 		printf("%s\n", map->matrix[i]);
// 	printf("print_matrix: Map properties: width(%d)  height(%d)\n",
// 		map->width, map->height);
// }

t_map	*init_map(t_list *lst)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_putendl_fd(RED "Error" RESET MEM_ALLOCATE_ERR, STDERR_FILENO);
		return (NULL);
	}
	map->width = find_max_len(lst);
	map->height = ft_lstsize(lst);
	map->matrix = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->matrix)
		return (NULL);
	fill_matrix(map, lst);
	if (!check_map(map))
		return (NULL);
	return (map);
}
