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

void	set_default(t_cube *cube)
{
	static int arr[8][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
	};
	cube->map.arr = &arr[0][0];
	cube->window.width = WIDTH;
	cube->window.height = HEIGHT;
	cube->player.speed = 300.0;
	cube->map.rows = 8;
	cube->map.cols = 8;
	cube->map.wall_width = cube->window.width / cube->map.cols;
	cube->map.wall_height = cube->window.height / cube->map.rows;
}

int	main(void)
{
	t_cube	cube;

	ft_bzero(&cube, sizeof(t_cube));
	set_default(&cube);
	mlx_start_loop(&cube);
	return (0);
}
