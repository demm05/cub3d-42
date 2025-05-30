/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:56:33 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/27 11:07:18 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_PRIVATE_H
# define WORLD_PRIVATE_H

# include "cube.h"

t_list	*read_file(const char *path);

// int		init_world(void *mlx_ptr, t_world *world, const char *path);

int		parse_textures(void *mlx_ptr, t_world *world, t_list **lst);

/**
 * @brief Frees the memory allocated for the map.
 * 
 * @param map Pointer to the t_map structure to be freed.
 */
void	destroy_map(t_map *map);

/**
 * @brief Parses a map from a file.
 * 
 * @param lst A list containing the lines read from the map file.
 * @return Pointer to a t_map structure allocated with malloc.
 */
t_map	*init_map(t_list *lst);

#endif
