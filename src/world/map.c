#include "world_private.h"

MAYBE_INLINE char	map_get(t_world *wrd, int x, int y)
{
	return (wrd->map.matrix[y][x]);
}
