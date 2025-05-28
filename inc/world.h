/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:56:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/27 14:41:49 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

// # define MAP_WIDTH 24
// # define MAP_HEIGHT 24

# include "cube.h"

typedef struct s_map
{
	char	**matrix;
	size_t	width;
	size_t	height;
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

/**
 * @brief Parses a map from a file.
 * 
 * @param lst A list containing the lines read from the map file.
 * @return Pointer to a t_map structure allocated with malloc.
 */
t_map	*init_map(t_list *lst);

int		init_world(void *mlx_ptr, t_world *world, const char *path);

/**
 * @brief Frees the memory allocated for the map.
 * 
 * @param map Pointer to the t_map structure to be freed.
 */
void	destroy_map(t_map *map);

void	world_destroy(void *mlx_ptr, t_world *world);

#endif
