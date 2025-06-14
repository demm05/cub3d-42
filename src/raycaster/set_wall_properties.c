#include "raycaster_private.h"
#include <math.h>

MAYBE_INLINE void	ray_set_wall_prop(t_engine *eng, t_ray *ray)
{
	double	wall_hit;

	if (ray->side == 0)
		wall_hit = eng->camera.pos.y + ray->wall_dist * ray->direction.y;
	else
		wall_hit = eng->camera.pos.x + ray->wall_dist * ray->direction.x;
	wall_hit -= floor(wall_hit);
	char	wall;

	wall = map_get(eng->map, ray->map.x, ray->map.y);
	ray->texture = &eng->textures.walls.img_arr[wall - '1'];
	if (ray->side == 0 && ray->direction.x > 0)
	{
		ray->floor_wall.x = ray->map.x;
		ray->floor_wall.y = ray->map.y + wall_hit;
	}
	else if (ray->side == 0 && ray->direction.x < 0)
	{
		ray->floor_wall.x = ray->map.x + 1.0;
		ray->floor_wall.y = ray->map.y + wall_hit;
	}
	else if (ray->side == 1 && ray->direction.y > 0)
	{
		ray->floor_wall.x = ray->map.x + wall_hit;
		ray->floor_wall.y = ray->map.y;
	}
	else
	{
		ray->floor_wall.x = ray->map.x + wall_hit;
		ray->floor_wall.y = ray->map.y + 1.0;
	}
	ray->x_on_tex = (int)(wall_hit * (double)ray->texture->width);
    if ((ray->side == 0 && ray->direction.x < 0) || (ray->side == 1 && ray->direction.y > 0))
        ray->x_on_tex = ray->texture->width - ray->x_on_tex - 1;
    if (ray->x_on_tex < 0)
    	ray->x_on_tex = 0;
    if (ray->x_on_tex >= ray->texture->width)
    	ray->x_on_tex = ray->texture->width - 1;
}

