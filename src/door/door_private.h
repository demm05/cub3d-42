/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:34:18 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/26 17:14:36 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_PRIVATE_H
# define DOOR_PRIVATE_H

# include "cube.h"

# define DOOR_ANIMATION_DURATION 2000.0
# define DOOR_OPEN_DURATION 5000.0

typedef struct s_door_private_state
{
	double			max_dist;
	double			max_offset;
	double			offset;
	double			best_dot;
	double			dot;
	double			dx;
	double			dy;
	double			dist;
	t_vec2_double	perp;
	t_vec2_double	door_vec;
	t_door			*nearest;
}	t_door_private_state;

#endif  //!DOOR_PRIVATE_H