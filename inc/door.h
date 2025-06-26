/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:35:40 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/26 16:42:35 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

# include "cube.h"
# include "math.h"

typedef struct s_door
{
	int			x;
	int			y;
	double		animation;
	bool		ready_to_open;
	bool		is_open;
	bool		is_closing;
	size_t		start_time;
}	t_door;

typedef struct s_doors
{
	t_door	*doors;
	int		len;
}	t_doors;

t_door	*get_nearby_closed_door(t_camera *player, t_doors *doors);

void	handle_door_interaction(t_door *door, bool *opening_door);

void	update_doors(t_doors *doors, t_map **map, t_camera *player, double dt);

char	get_tile_with_doors(t_doors *doors, int x, int y, char **map);

void	print_doors(t_doors *doors);

t_door	*get_door_by_pos(t_doors *doors, int x, int y);

#endif  //!__DOOR__H__