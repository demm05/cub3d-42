#include "engine_private.h"
#include <math.h>

void	update_lookup_table(t_engine *eng)
{
	free(eng->table.floor_dist);
	eng->table.floor_dist = malloc(sizeof(double) * eng->window.height);
	int h = eng->window.height + 1;
	for (int y = 0; y < h; y++)
		eng->table.floor_dist[y] = fabs(h / (2.0 * y - h));
}
