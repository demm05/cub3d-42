/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:51:00 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/16 12:27:36 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include "cube.h"
# include "dirent.h"

typedef struct s_raw_texture
{
	char	*name;
	char	*path;
}	t_raw_textrure;

t_list	*read_file(const char *path);

// int		init_world(void *mlx_ptr, t_world *world, const char *path);

char	**get_names(t_list *lst);

int		init_texture_arr(t_image **textures_arr,
			t_textures *textures, bool mode);
int		init_texture_names_arr(char **textures_path);

int		init_texture_pointers(t_textures *textures, bool mode);

int		init_sprites_arr(t_sprite **sprites, t_textures *textures, bool mode);
int		init_sprites_dir_names_arr(char **dir_path);

#endif