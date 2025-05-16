/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:17:05 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:17:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include <stdbool.h>

typedef struct s_mlx_data	t_mlx_data;

typedef struct s_player
{
	bool	moving_up;
	bool	moving_down;
	bool	moving_left;
	bool	moving_right;
	int		x;
	int		y;
}	t_player;

typedef struct s_window
{
	int	width;
	int	height;
}	t_window;

typedef struct s_cube
{
	t_player	player;
	t_window	window;
	t_mlx_data	*mlx;
}	t_cube;

#endif
