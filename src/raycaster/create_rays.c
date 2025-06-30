/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:37:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 15:37:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_private.h"

bool	allocate_rays(t_engine *eng)
{
	t_ray	*rays;
	int		x;

	rays = ft_calloc(eng->window.max_width, sizeof(t_ray));
	if (!rays)
		return (0);
	x = -1;
	while (++x < eng->window.max_width)
		rays[x].index = x;
	eng->rays = rays;
	return (1);
}

void	destroy_rays(t_engine *eng)
{
	free(eng->rays);
}
