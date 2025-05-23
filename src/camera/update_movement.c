#include "camera_private.h"
#include <math.h>

MAYBE_INLINE void	update_movements(t_camera *cam, t_input *inp)
{
	double move_amount;

	move_amount = 0.1;
	if (inp->moving_up)
	{
		cam->pos.y += cam->dir.y * move_amount;
		cam->pos.x += cam->dir.x * move_amount;
	}
	if (inp->moving_down)
	{
		cam->pos.y -= cam->dir.y * move_amount;
		cam->pos.x -= cam->dir.x * move_amount;
	}
	if (inp->moving_left)
	{
      double oldDirX = cam->dir.x;
      cam->dir.x = cam->dir.x * cos(move_amount) - cam->dir.y* sin(move_amount);
      cam->dir.y = oldDirX * sin(move_amount) + cam->dir.y * cos(move_amount);
      double oldPlaneX = cam->plane.x;
      cam->plane.x = cam->plane.x * cos(move_amount) - cam->plane.y * sin(move_amount);
      cam->plane.y = oldPlaneX * sin(move_amount) + cam->plane.y * cos(move_amount);
	}
	if (inp->moving_right)
	{
      double oldDirX = cam->dir.x;
      cam->dir.x = cam->dir.x * cos(-move_amount) - cam->dir.y* sin(-move_amount);
      cam->dir.y = oldDirX * sin(-move_amount) + cam->dir.y * cos(-move_amount);
      double oldPlaneX = cam->plane.x;
      cam->plane.x = cam->plane.x * cos(-move_amount) - cam->plane.y * sin(-move_amount);
      cam->plane.y = oldPlaneX * sin(-move_amount) + cam->plane.y * cos(-move_amount);
	}
}

