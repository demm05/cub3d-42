/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:35:40 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/23 17:32:43 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

# include "cube.h"
# include "math.h"

typedef enum e_door_dir
{
	DOOR_DIR_H,
	DOOR_DIR_V
}	t_door_dir;

typedef struct s_door
{
	int			x;
	int			y;
	int			sprite_pos;
	double		animation;
	bool		ready_to_open;
	bool		is_open;
	double		timer;
	t_door_dir	dir;
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