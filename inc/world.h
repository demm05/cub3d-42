/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:56:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/30 16:25:42 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

// # define MAP_WIDTH 24
// # define MAP_HEIGHT 24

# include "cube.h"

typedef struct s_map
{
	char		**matrix;
	int			width;
	int			height;
	t_point		player_pos;
}	t_map;


/**
 * @param no path to the north texture
 * @param so path to the south texture
 * @param we path to the west texture
 * @param ea path to the east texture
 * @param f flor color in RGB format 
 * ( R,G,B colors in range [0,255]: 0, 255, 255 )
 * @param c ceiling color in RGB format
 * ( R,G,B colors in range [0,255]: 0, 255, 255 )
 */
typedef struct s_world
{
	t_image	no;
	t_image	so;
	t_image	we;
	t_image	ea;
	int		f;
	int		c;
	t_map	*map;
}	t_world;

int		world_init(void *mlx_ptr, t_world *world, const char *path);
void	world_destroy(void *mlx_ptr, t_world *world);

char	map_get(t_world *wrd, int x, int y);

/**
 * @brief Frees the memory allocated for the map.
 * 
 * @param map Pointer to the t_map structure to be freed.
 */
void	destroy_map(t_map *map);

#endif
