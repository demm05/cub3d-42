/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:43 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:43 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(void)
{
	t_cube	cube;

	ft_bzero(&cube, sizeof(t_cube));
	cube.window.width = WIDTH;
	cube.window.height = HEIGHT;
	cube.player.speed = 1700.0;
	mlx_start_loop(&cube);
	return (0);
}
