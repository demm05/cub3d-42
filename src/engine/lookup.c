/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:28:52 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 12:03:22 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"
#include <math.h>

bool	update_lookup_table(t_engine *eng)
{
	int	h;
	int	y;

	h = eng->window.height + 1;
	free(eng->table.y);
	eng->table.y = malloc(sizeof(struct s_cord_y) * h);
	if (!eng->table.y)
		return (0);
	y = 0;
	while (y < h)
	{
		eng->table.y[y].floor_dist = fabs(h / (2.0 * y - h));
		eng->table.y[y].brightness = 1
			- (eng->table.y[y].floor_dist / FOG_DISTANCE);
		y++;
	}
	return (1);
}
