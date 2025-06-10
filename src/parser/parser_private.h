/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:51:00 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/10 12:25:30 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include "cube.h"
# include "dirent.h"

# define _TEXTURE_COUNT 5
# define _SPRITE_COUNT 3

t_list	*read_file(const char *path);

// int		init_world(void *mlx_ptr, t_world *world, const char *path);

char	**get_names(t_list *lst);

int		init_texture_arr(t_image **textures_arr, t_textures *textures);
int		init_texture_path_arr(char **textures_path);

int		init_sprites_arr(t_sprite **sprites, t_textures *textures);
int		init_sprites_dir_arr(char **dir_path);

#endif