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

# include <stdbool.h>
# include <aio.h>

typedef struct s_fps t_fps;

typedef struct s_window
{
	void	*mlx; // Just a pointer to t_cube->mlx
	void	*win;
	void	*img;
	char	*buffer;
	size_t	frame_start_time;
	int		depth;
	int		line_size;
	int		endian;
	int		width;
	int		height;
	int		frames;
}	t_window;

typedef struct s_player
{
	bool	moving_up;
	bool	moving_down;
	bool	moving_left;
	bool	moving_right;
	int		x;
	int		y;
}	t_player;

typedef struct s_cube
{
	t_player	player;
	t_window	window;
	void		*mlx;
}	t_cube;

#endif
