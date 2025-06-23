/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:28:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:28:57 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"

MAYBE_INLINE void	minimap_update_properties(t_engine *eng)
{
	t_minimap	*map;

	map = &eng->minimap;
	map->cubes.x = eng->map->width;
	map->cubes.y = eng->map->height;
	map->cub_size.x = eng->window.width / map->cubes.x / MAP_SIZEOF_MINIMAP;
	map->cub_size.y = eng->window.height / map->cubes.y / MAP_SIZEOF_MINIMAP;
	map->draw_size.x = map->cubes.x * map->cub_size.x;
	map->draw_size.y = map->cubes.y * map->cub_size.y;
	map->draw_start.x = eng->window.width - \
		(map->draw_size.x + MAP_BORDER_OFFSET + MAP_BORDER_SIZE);
	map->draw_start.y = MAP_BORDER_OFFSET + MAP_BORDER_SIZE;
	map->entity_size.x = map->cub_size.x / MAP_PLAYER_PROPORTION;
	map->entity_size.y = map->cub_size.y / MAP_PLAYER_PROPORTION;
	if (map->entity_size.x < 1 || map->entity_size.y < 1)
		map->is_player_displayable = 0;
	else
		map->is_player_displayable = 1;
#if DEBUG
	printf("Minimap new properties: cub: %dx%d\tentity: %dx%d\ts: %dx%d\te: %dx%d\n",
		map->cub_size.x, map->cub_size.y, map->entity_size.x,
		map->entity_size.y, map->draw_start.x, map->draw_start.y,
		map->draw_size.x, map->draw_size.y);
#endif
}

MAYBE_INLINE void	minimap_toggle(t_engine *eng)
{
	eng->minimap.display_minimap = !eng->minimap.display_minimap;
}
