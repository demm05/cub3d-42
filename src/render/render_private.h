/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:57:32 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 10:40:49 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_PRIVATE_H
# define RENDER_PRIVATE_H

# include "cube.h"

# define MAP_BORDER_OFFSET 5
# define MAP_CUBE_GAP 1
# define MAP_SIZEOF_MINIMAP 6
# define MAP_BORDER_COLOR 0x303030u
# define MAP_BORDER_SIZE 3
# define MAP_PLAYER_PROPORTION 2.0
# define MAP_CUBE_FULL_COLOR 0xD3D3D3
# define MAP_CUBE_EMPTY_COLOR 0x802F4F4F
# define MAP_PLAYER_COLOR 0xFFA500

typedef struct s_minimap
{
	t_vec2_int		entity_size;
	t_vec2_int		cub_size;
	t_vec2_int		cubes;
	t_point			draw_start;
	t_point			draw_size;
	bool			is_player_displayable;
}	t_minimap;

#endif
