#include "render_private.h"

MAYBE_INLINE t_ui	minimap_draw(t_engine *eng, int x, int y, t_ui color)
{
	t_minimap	*m;

	(void)color;
	m = &eng->minimap;
	if (MAP_CUBE_GAP > 0 && \
		(x % m->cub_size.x >= m->cub_size.x - MAP_CUBE_GAP || \
		y % m->cub_size.y >= m->cub_size.y - MAP_CUBE_GAP))
		return (blend_normal(color, MAP_CUBE_EMPTY_COLOR));
	if (map_get(eng->map, x / m->cub_size.x, y / m->cub_size.y) < 1)
		return (blend_normal(color, MAP_CUBE_EMPTY_COLOR));
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

MAYBE_INLINE void	render_minimap(t_engine *eng)
{
	if (!eng->minimap.display_minimap || !eng->minimap.is_player_displayable)
		return ;
	draw_from_to_each(eng, eng->minimap.draw_start, eng->minimap.draw_size,
		minimap_draw);
	minimap_draw_borders(eng, &eng->minimap);
	minimap_draw_player(eng, &eng->minimap);
}
