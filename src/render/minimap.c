#include "render_private.h"
#include <math.h>

MAYBE_INLINE void	minimap_update_properties(t_engine *eng)
{
	t_minimap	*map;

	map = eng->minimap;
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

bool	minimap_create(t_engine *eng)
{
	eng->minimap = malloc(sizeof(t_minimap));
	if (!eng->minimap)
		return (0);
	return (1);
}

MAYBE_INLINE t_ui	minimap_draw(t_engine *eng, int x, int y, t_ui color)
{
	t_minimap	*m;

	(void)color;
	m = eng->minimap;
	if (MAP_CUBE_GAP > 0 && \
		(x % m->cub_size.x >= m->cub_size.x - MAP_CUBE_GAP || \
		y % m->cub_size.y >= m->cub_size.y - MAP_CUBE_GAP))
		return (blend_normal(color, MAP_CUBE_EMPTY_COLOR));
	if (map_get(eng->map, x / m->cub_size.x, y / m->cub_size.y) < 1)
		return (blend_normal(color, MAP_CUBE_EMPTY_COLOR));
	if (map_get_c(eng->map, x / m->cub_size.x, y / m->cub_size.y) == 'd')
		return (MAP_CUBE_DOOR_COLOR);
	return (MAP_CUBE_FULL_COLOR);
}

MAYBE_INLINE void	minimap_draw_borders(t_engine *eng, t_minimap *m)
{
	// LEFT
	draw_rectangle(eng,
		(t_point){m->draw_start.x - MAP_BORDER_SIZE, m->draw_start.y},
		(t_point){MAP_BORDER_SIZE, m->draw_size.y},
		MAP_BORDER_COLOR);
	// RIGHT
	draw_rectangle(eng,
		(t_point){m->draw_start.x + m->draw_size.x - MAP_CUBE_GAP, m->draw_start.y - MAP_BORDER_SIZE},
		(t_point){MAP_BORDER_SIZE, m->draw_size.y - MAP_CUBE_GAP + MAP_BORDER_SIZE},
		MAP_BORDER_COLOR);
	// TOP
	draw_rectangle(eng,
		(t_point){m->draw_start.x - MAP_BORDER_SIZE, m->draw_start.y - MAP_BORDER_SIZE},
		(t_point){m->draw_size.x + MAP_BORDER_SIZE, MAP_BORDER_SIZE}, MAP_BORDER_COLOR);
	// DOWN
	draw_rectangle(eng,
		(t_point){m->draw_start.x - MAP_BORDER_SIZE, m->draw_start.y + m->draw_size.y - MAP_CUBE_GAP},
		(t_point){m->draw_size.x + MAP_BORDER_SIZE * 2, MAP_BORDER_SIZE}, MAP_BORDER_COLOR);
}

MAYBE_INLINE void	minimap_draw_player(t_engine *eng, t_minimap *map)
{
	t_point	player;

	player.x = eng->camera.pos.x * map->cub_size.x - map->entity_size.x \
		/ MAP_PLAYER_PROPORTION;
	player.y = eng->camera.pos.y * map->cub_size.y - map->entity_size.y \
		/ MAP_PLAYER_PROPORTION;
	draw_rectangle(eng,
		(t_point){map->draw_start.x + player.x, map->draw_start.y + player.y},
		(t_point){map->entity_size.x, map->entity_size.y}, MAP_PLAYER_COLOR);
}

MAYBE_INLINE void	draw_minimap(t_engine *eng)
{
	if (!eng->minimap->is_player_displayable)
		return ;
	draw_from_to_each(eng, eng->minimap->draw_start, eng->minimap->draw_size,
		minimap_draw);
	minimap_draw_borders(eng, eng->minimap);
	minimap_draw_player(eng, eng->minimap);
}
