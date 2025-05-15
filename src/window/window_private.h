/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:35 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_PRIVATE_H
# define WINDOW_PRIVATE_H

# include "mlx.h"
# include "window.h"

int			destroy_event(t_cube *cube);
void		hook_events(t_cube *cube);
t_mlx_data	*create_window(t_window *win);
int			mlx_handle_keyboard(int keycode, t_cube *cube);

int			mlx_handle_mouse_press(int key, int x, int y, t_cube *cube);
int			mlx_handle_mouse_move(int x, int y, t_cube *cube);
void		mlx_free(t_mlx_data **arg);
void		mlx_enable_window_resize(t_mlx_data *mlx);

#endif
