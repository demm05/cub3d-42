#include "engine_private.h"
#include "sys/time.h"

static inline size_t	get_current_time_microseconds(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	eng_new_frame(t_timing *tm)
{
	size_t	current_time;

	current_time = get_current_time_microseconds();
	tm->delta_time = (double)(current_time - tm->frame_start) / 1000000.0;
	tm->frame_start = current_time;
	if (tm->delta_time > MAX_DELTA_TIME)
		tm->delta_time = MAX_DELTA_TIME;
	tm->frame_count++;
}
