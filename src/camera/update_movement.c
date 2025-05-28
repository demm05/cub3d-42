#include "camera_private.h"
#include <math.h>

MAYBE_INLINE void	update_movements(t_camera *cam, t_input *inp)
{
	double	move_amount;
	double	old_dir_x;
	double	old_plane_x;

	double 	pos_x;
	double	pos_y;

	move_amount = 0.01;
	if (inp->moving_up)
	{
		pos_y = cam->pos.y + cam->dir.y * move_amount;
		pos_x = cam->pos.x + cam->dir.x * move_amount;
		if (pos_x > 0 && pos_y >0  && g_world.map->matrix[(int)pos_y][(int)pos_x] != '1')
		{
			cam->pos.y = pos_y;
			cam->pos.x = pos_x;
		}
	}
	if (inp->moving_down)
	{
		pos_y = cam->pos.y - cam->dir.y * move_amount;
		pos_x = cam->pos.x - cam->dir.x * move_amount;
		if (pos_x > 0 && pos_y > 0 && g_world.map->matrix[(int)pos_y][(int)pos_x] != '1')
		{
			cam->pos.y = pos_y;
			cam->pos.x = pos_x;
		}
		// cam->pos.y -= cam->dir.y * move_amount;
		// cam->pos.x -= cam->dir.x * move_amount;
	}
	if (inp->moving_left)
	{
		old_dir_x = cam->dir.x;
		cam->dir.x = cam->dir.x * cos(move_amount) - cam->dir.y * sin(move_amount);
		cam->dir.y = old_dir_x * sin(move_amount) + cam->dir.y * cos(move_amount);
		old_plane_x = cam->plane.x;
		cam->plane.x = cam->plane.x * cos(move_amount) - cam->plane.y * sin(move_amount);
		cam->plane.y = old_plane_x * sin(move_amount) + cam->plane.y * cos(move_amount);
	}
	if (inp->moving_right)
	{
		old_dir_x = cam->dir.x;
		cam->dir.x = cam->dir.x * cos(-move_amount) - cam->dir.y * sin(-move_amount);
		cam->dir.y = old_dir_x * sin(-move_amount) + cam->dir.y * cos(-move_amount);
		old_plane_x = cam->plane.x;
		cam->plane.x = cam->plane.x * cos(-move_amount) - cam->plane.y * sin(-move_amount);
		cam->plane.y = old_plane_x * sin(-move_amount) + cam->plane.y * cos(-move_amount);
	}
}
