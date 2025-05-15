/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:03 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:03 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"
#include <X11/keysym.h>

int	mlx_handle_keyboard(int keycode, t_cube *cube)
{
	(void) cube;
	(void) keycode;
	return (0);
}
