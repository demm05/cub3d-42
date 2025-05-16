#include <stdio.h>  // For perror, fprintf
#include <unistd.h>
#include <time.h>

typedef struct {
    long long frame_count;
    double fps;
    double update_interval_seconds;
    struct timespec last_time;
} FPS_Counter;

int fps_counter_init(FPS_Counter* counter, double update_interval_seconds) {
    if (!counter) {
        return -1;
    }

    counter->frame_count = 0;
    counter->fps = 0.0;
    counter->update_interval_seconds = update_interval_seconds > 0 ? update_interval_seconds : 1.0;

    // _POSIX_TIMERS check is mostly for very old systems or non-compliant ones.
    // Modern Linux systems fully support CLOCK_MONOTONIC.
#if defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0
    if (clock_gettime(CLOCK_MONOTONIC, &counter->last_time) != 0) {
        perror("FPSCounter Error: clock_gettime(CLOCK_MONOTONIC) failed");
        return -1;
    }
#else
    // Fallback if somehow _POSIX_TIMERS is not defined or indicates no support,
    // though this is highly unlikely on a modern Linux system.
    // Using CLOCK_REALTIME is less ideal as it's affected by system time changes.
    fprintf(stderr, "FPSCounter Warning: CLOCK_MONOTONIC might not be supported or _POSIX_TIMERS not checked. Attempting clock_gettime anyway or consider CLOCK_REALTIME as a less precise fallback.\n");
    if (clock_gettime(CLOCK_MONOTONIC, &counter->last_time) != 0) { // Still try CLOCK_MONOTONIC
        perror("FPSCounter Error: clock_gettime(CLOCK_MONOTONIC) failed after warning");
        return -1; // Or attempt with CLOCK_REALTIME if truly necessary for some edge case
    }
#endif
    return 0;
}

int fps_counter_tick(FPS_Counter* counter) {
    if (!counter) {
        return 0;
    }

    counter->frame_count++;
    struct timespec current_time;

    if (clock_gettime(CLOCK_MONOTONIC, &current_time) != 0) {
        perror("FPSCounter Error: clock_gettime in tick failed");
        // Potentially skip this tick's update or handle error
        return 0;
    }

    double elapsed_seconds = (double)(current_time.tv_sec - counter->last_time.tv_sec) +
                             (double)(current_time.tv_nsec - counter->last_time.tv_nsec) / 1000000000.0;

    if (elapsed_seconds >= counter->update_interval_seconds) {
        if (elapsed_seconds > 0) { // Avoid division by zero if interval is extremely small / timer issue
            counter->fps = (double)counter->frame_count / elapsed_seconds;
        } else {
            counter->fps = 0; // Or some indicator of an issue
        }
        counter->frame_count = 0;
        counter->last_time = current_time;
        return 1; // FPS was updated
    }
    return 0; // FPS not updated yet
}

double fps_counter_get_fps(const FPS_Counter* counter) {
    if (!counter) {
        return 0.0;
    }
    return counter->fps;
}
