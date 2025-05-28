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
	double			wall_x_cord;
	int				wall_face_hit;
	int				line_height;
	int				draw_start;
	int				draw_end;
	bool			side;
}	t_ray;

void	cast_walls(t_engine *eng, t_ray *ray);

#endif
