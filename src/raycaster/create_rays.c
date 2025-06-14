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
