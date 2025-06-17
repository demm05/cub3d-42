#include "raycaster_private.h"

MAYBE_INLINE void	ray_set_floor_prop(t_engine *eng, t_ray *ray)
{
	(void)eng;
	if (ray->side == 0 && ray->direction.x > 0)
	{
		ray->floor_wall.x = ray->map.x;
		ray->floor_wall.y = ray->map.y + ray->wall_hit;
	}
	else if (ray->side == 0 && ray->direction.x < 0)
	{
		ray->floor_wall.x = ray->map.x + 1.0;
		ray->floor_wall.y = ray->map.y + ray->wall_hit;
	}
	else if (ray->side == 1 && ray->direction.y > 0)
	{
		ray->floor_wall.x = ray->map.x + ray->wall_hit;
		ray->floor_wall.y = ray->map.y;
	}
	else
	{
		ray->floor_wall.x = ray->map.x + ray->wall_hit;
		ray->floor_wall.y = ray->map.y + 1.0;
	}
}
