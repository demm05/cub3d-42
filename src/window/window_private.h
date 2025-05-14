#ifndef WINDOW_PRIVATE_H
#define WINDOW_PRIVATE_H

#include "minilibx/mlx.h"
#include "window.h"

void        mlx_free(t_mlx_data *data);
int         destroy_event(t_cube *cube);
void        hook_events(t_cube *cube);
t_mlx_data *create_window(void);

#endif
