/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:31:01 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 17:07:29 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "types.h"

# define MAP_BORDER_OFFSET 5
# define MAP_CUBE_GAP 1
# define MAP_SIZEOF_MINIMAP 5
# define MAP_BORDER_SIZE 3
# define MAP_PLAYER_PROPORTION 2.0
# define MAP_BORDER_COLOR 0x303030u
# define MAP_CUBE_FULL_COLOR 0xD3D3D3
# define MAP_CUBE_EMPTY_COLOR 0x802F4F4F
# define MAP_PLAYER_COLOR 0xFFA500
# define MAP_CUBE_DOOR_COLOR 0x899499

typedef struct s_minimap
{
	t_vec2_int		entity_size;
	t_vec2_int		cub_size;
	t_vec2_int		cubes;
	t_point			draw_start;
	t_point			draw_size;
	bool			is_player_displayable;
	bool			display_minimap;
}	t_minimap;

void	minimap_update_properties(t_engine *eng);
void	minimap_toggle(t_engine *eng);
void	render_minimap(t_engine *eng);

#endif
