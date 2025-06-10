/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:00:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/10 11:50:21 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include "cube.h"

# define _CEILING_PATH "assets/north.xpm"
# define _FLOOR_PATH "assets/south.xpm"
# define _PORTAL_IN_PATH "assets/west.xpm"
# define _PORTAL_OUT_PATH "assets/west.xpm"

# define _WALLS_DIR_PATH "assets/walls/"
# define _DOOR_DIR_PATH "assets/door/"

enum e_sprites
{
	_E_DOOR,
	_E_WALLS,
	_E_NULL
};

enum e_textures
{
	_E_CEILING,
	_E_FLOOR,
	_E_PORTAL_IN,
	_E_PORTAL_OUT,
	_E_NULL_T
};

typedef struct s_sprite
{
	t_image	*img_arr;
	int		len;
}	t_sprite;

typedef struct s_sprite	t_images;

typedef struct s_textures
{
	t_images	walls;
	t_image		ceiling;
	t_image		floor;
	t_image		portal_in;
	t_image		portal_out;
	t_sprite	door;
}	t_textures;

#endif