/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:54:05 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/06 14:52:19 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cube.h"

typedef struct s_map
{
	char		**matrix;
	int			width;
	int			height;
	t_point		player_pos;
}	t_map;

/**
 * @brief Parses a map from a file.
 * 
 * @param lst A list containing the lines read from the map file.
 * @return Pointer to a t_map structure allocated with malloc.
 */
t_map	*init_map(t_list *lst);

/**
 * @brief Initialise textures from image files.
 * 
 * @param mlx_ptr    A pointer to the MLX instance.
 * @param textures   A pointer to a t_textures structure that will be filled.
 * 
 * @return 0 on success, -1 on failure.
 */
int		init_textures(void *mlx_ptr, t_textures *textures);

/**
 * @brief Free all memory allocated for the map.
 * 
 * @param map A pointer to the t_map structure to be destroyed.
 */
void	destroy_map(t_map *map);

/**
 * @brief Frees all loaded textures.
 * 
 * @details This includes both single static textures (e.g., walls, floor)
 * and animated or multi-frame sprite textures (e.g., doors).
 * 
 * @param mlx_ptr A pointer to the MLX instance used to create the textures.
 * @param textures A pointer to the t_textures structure containing all textures.
 */
void	destroy_textures(void *mlx_ptr, t_textures *textures);

#endif  //!__PARSER__H__