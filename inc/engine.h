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

typedef struct s_settings
{
	float	ui_scale;
}	t_settings;

typedef struct s_lookup
{
	struct s_cord_y
	{
		double	floor_dist;
		double	brightness;
	}	*y;
}	t_lookup;

typedef struct s_window
{
	void	*mlx;	// Pointer to mlx instance
	void	*win;
	int		width;
	int		height;
	int		max_width;
	int		max_height;
	char	*title;
	bool	resizing;
}	t_window;

typedef struct s_engine
{
	bool		draw_new_frame;
	void		*mlx;
	t_map		*map;
	t_ray		*rays;
	t_freetype	*freetype;
	t_window	window;
	t_frame_buf	main_buffer;
	t_input		input;
	t_textures	textures;
	t_camera	camera;
	t_timing	timing;
	t_minimap	minimap;
	t_lookup	table;
	t_state		state;
	t_menu		menu;
	t_doors		doors;
	t_entity	player;
	t_settings	setting;
}	t_engine;

bool	engine_init(t_engine *eng, char *map_path);
int		engine_loop(t_engine *eng);
void	engine_destroy(t_engine *eng);
void	eng_new_frame(t_engine *eng);
bool	update_lookup_table(t_engine *eng);
void	enging_loop_stop(t_engine *eng);
void	animation_start(t_animation *anim);
t_image	*animation_get_image(t_animation *anim);
void	animation_change_sprite(t_animation *anim, t_sprite *sp);

#endif
