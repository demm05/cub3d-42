#include "render_private.h"

MAYBE_INLINE void	minimap_update_properties(t_engine *eng)
{
	t_minimap	*map;

	map = &eng->map;
	map->cubes.x = eng->world.map->width;
	map->cubes.y = eng->world.map->height;
	map->cub_size.x = eng->window.width / map->cubes.x / map->size_on_window;
	map->cub_size.y = eng->window.height / map->cubes.y / map->size_on_window;
	map->draw_size.x = map->cubes.x * map->cub_size.x;
	map->draw_size.y = map->cubes.y * map->cub_size.y;
	map->draw_start.x = eng->window.width - (map->draw_size.x + map->border_offset);
	map->draw_start.y = map->border_offset;
	map->entity_size.x = map->cub_size.x / 3;
	map->entity_size.y = map->cub_size.y / 3;
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

MAYBE_INLINE unsigned int minimap_draw(t_engine *eng, int x, int y, unsigned int color)
{
	t_minimap	*map;

	(void)color;
	map = &eng->map;
	if (map->cube_gap > 0 && (x % map->cub_size.x >= map->cub_size.x - map->cube_gap || \
		y % map->cub_size.y >= map->cub_size.y - map->cube_gap))
		return (color);
	if (map_get(&eng->world, x / map->cub_size.x, y / map->cub_size.y) < '1')
		return (color);
	return (0xFFcfa1);
}

