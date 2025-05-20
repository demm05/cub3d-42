#include "window_private.h"
#include "sys/time.h"

MAYBE_INLINE size_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

MAYBE_INLINE long long get_current_time_microseconds(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((long long)tv.tv_sec * 1000000 + tv.tv_usec);
}

MAYBE_INLINE void	fps_win_tick(t_window *win)
{
	size_t	current_time;

	win->frames++;
	current_time = get_current_time();
	if (current_time - win->frame_zero_time >= 1000)
	{
		win->fps = win->frames;
		win->frame_zero_time = current_time;
		win->frames = 0;
	}
}
