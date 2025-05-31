/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:57:55 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 11:30:27y dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "cube.h"

typedef struct s_window
{
	void	*mlx;	// Pointer to mlx instance
	void	*win;
	int		width;
	int		height;
	int		max_width;
	int		max_height;
	char	*title;
}	t_window;

typedef struct s_engine
{
	void		*mlx;
	t_window	window;
	t_input		input;
	t_frame_buf	main_buffer;
	t_world		world;
	t_camera	camera;
	t_ray		*rays;
	t_timing	timing;
}	t_engine;

bool	engine_init(t_engine *eng, char *map_path);
int		engine_loop(t_engine *eng);
void	engine_destroy(t_engine *eng);
void	eng_new_frame(t_timing *timing);

#endif
