/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_by_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:02:06 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/18 15:08:02 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_private.h"

t_door	*get_door_by_pos(t_doors *doors, int x, int y)
{
	int	i;

	i = 0;
	if (!doors || !doors->doors || doors->len <= 0)
		return (NULL);
	while (i < doors->len)
	{
		if (doors->doors[i].x == x && doors->doors[i].y == y)
			return (&doors->doors[i]);
		i++;
	}
	return (NULL);
}
