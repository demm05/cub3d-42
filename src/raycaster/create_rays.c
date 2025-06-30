/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:39 by dmelnyk          ###   ########.fr       */
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
#if DEBUG
	puts("allocate_rays: Successfully allocated\n");
#endif
	return (1);
}

void	destroy_rays(t_engine *eng)
{
	free(eng->rays);
}
