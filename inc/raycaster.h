/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:01:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 10:09:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "cube.h"

typedef struct s_ray
{
	t_vec2_double	direction;
	t_vec2_double	side_dist;
	t_vec2_double	delta;
	t_vec2_int		step;
	t_vec2_int		map;
	double			wall_dist;
	int				wall_face_hit;
	int				index;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				x_on_tex;
	t_image			*texture;
	double			floor_x_wall;
	double			floor_y_wall;
	bool			side;
	struct s_floor
	{
		t_vec2_int	step;
		t_point		pos;
	}	floor;
}	t_ray;

// typedef struct s_ray
// {
// 	int				index;
// 	int				line_height;
// 	struct s_wall
// 	{
// 		bool	side;
// 		int		start;
// 		int		end;
// 		int		tex_x;
// 		int		face_hit;
// 		double	wall_dist;
// 		t_image	*texture;
// 	}	wall;
// 	t_vec2_double	direction;
// 	t_vec2_double	side_dist;
// 	t_vec2_double	delta;
// 	t_vec2_int		step;
// 	t_vec2_int		map;
// }	t_ray;

bool	allocate_rays(t_engine *eng);
void	destroy_rays(t_engine *eng);
void	cast_ray(t_engine *eng, t_ray *ray, int h, int w);
void	ray_set_wall_prop(t_engine *eng, t_ray *ray);

#endif
