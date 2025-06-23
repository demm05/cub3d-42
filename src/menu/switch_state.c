/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:29:22 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	menu_switch_state(t_engine *eng)
{
	if (!eng)
		return ;
#if DEBUG
	printf("Switching from state %d\n", eng->state);
#endif
	ft_bzero(&eng->input, sizeof(t_input));
	if (eng->state == MENU)
	{
		eng->state = PLAYING;
		mlx_mouse_hide(eng->mlx, eng->window.win);
	}
	else
	{
		eng->state = MENU;
		mlx_mouse_show(eng->mlx, eng->window.win);
	}
	eng->draw_new_frame = 1;
}
