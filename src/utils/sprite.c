#include "utils_private.h"

inline t_image	*sprite_get_img(t_images *sp, int i)
{
	return (&sp->img_arr[i % sp->len]);
}
