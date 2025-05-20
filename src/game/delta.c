#include "game_private.h"

MAYBE_INLINE void	set_delta(t_window *window)
{
	size_t	current_time;

	current_time = get_current_time_microseconds();
	window->timing.delta = (double)(current_time - window->timing.last_frame_time) / 1000000.0;
	window->timing.last_frame_time = current_time;
	if (window->timing.delta > MAX_DELTA_TIME)
		window->timing.delta = MAX_DELTA_TIME;
}

