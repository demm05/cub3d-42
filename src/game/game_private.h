/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:15:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/16 16:15:56 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_PRIVATE_H
# define GAME_PRIVATE_H

# include "game.h"

int game_handle_keyboard_press(int keycode, t_cube *cube);
int	game_handle_keyboard_release(int keycode, t_cube *cube);
int	game_handle_mouse_press(int key, int x, int y, t_cube *cube);
int	game_handle_mouse_move(int x, int y, t_cube *cube);

#endif
