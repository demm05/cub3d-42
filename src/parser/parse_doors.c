/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:00:31 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/20 13:09:41 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

void	print_doors(t_doors *doors)
{
	int	i;

	i = 0;
	while (i < doors->len)
	{
		printf("door[%i]:\n   x = %i\n   y = %i\n   anim = %f\n   timer = %f\n   is_open = %d\n   to_open = %d\n\n",
			i, doors->doors[i].x, doors->doors[i].y, doors->doors[i].animation,
			doors->doors[i].timer, doors->doors[i].is_open, doors->doors[i].ready_to_open);
		i++;
	}
}

static void	fill_doors(t_doors *doors, t_map *map)
{
	int	i;
	int	j;
	int	door_pos;

	i = 0;
	door_pos = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j] == 'd' && door_pos < doors->len)
			{
				doors->doors[door_pos].x = j;
				doors->doors[door_pos].y = i;
				door_pos++;
			}
			j++;
		}
		i++;
	}
}

static int	count_doors(t_map *map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j] == 'd')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	parse_doors(t_doors *doors, t_map *map)
{
	if (!doors || !map)
		return (-1);
	doors->len = count_doors(map);
	printf("doors len %i\n", doors->len);
	if (doors->len == 0)
		return (0);
	doors->doors = ft_calloc(doors->len, sizeof(t_door));
	if (!doors->doors)
	{
		ft_putendl_fd(RED "Error" RESET MEM_ALLOCATE_ERR, STDERR_FILENO);
		doors->len = 0;
		return (-1);
	}
	fill_doors(doors, map);
#if DEBUG
	print_doors(doors);
#endif
	return (0);
}
