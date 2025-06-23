/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:01:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 12:54:40 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "cube.h"

typedef struct s_door	t_door;

typedef struct s_ray
{
	t_vec2_double	direction;
	t_vec2_double	side_dist;
	t_vec2_double	delta;
	t_vec2_double	floor_wall;
	t_vec2_int		step;
	t_vec2_int		map;
	double			wall_dist;
	double			wall_hit;
	int				wall_face_hit;
	int				index;
	int				line_height;
	float			brightness;
	int				draw_start;
	int				draw_end;
	int				x_on_tex;
	t_image			*texture;
	bool			side;
	bool			skip_render;
	bool			is_door;
	t_door			*door_ptr;
}	t_ray;

bool	allocate_rays(t_engine *eng);
void	destroy_rays(t_engine *eng);
void	cast_ray(t_engine *eng, t_ray *ray, int h, int w);
void	cast_door(t_engine *eng, t_ray *ray, int h, int w);

#endif
