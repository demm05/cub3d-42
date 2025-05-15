/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:11 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

int	mlx_handle_mouse_press(int key, int x, int y, t_cube *cube)
{
	(void) cube;
	(void) key;
	(void) x;
	(void) y;
	return (0);
}

int	mlx_handle_mouse_move(int x, int y, t_cube *cube)
{
	(void) cube;
	(void) x;
	(void) y;
	return (0);
}
