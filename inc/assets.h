/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:00:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/16 12:27:01 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include "cube.h"

# define WEAPONS_COUNT 3

# define _CEILING_NAME "C"
# define _FLOOR_NAME "F"
# define _PORTAL_IN_NAME "P_IN"
# define _PORTAL_OUT_NAME "P_OUT"

# define _WALLS_DIR_NAME "WALLS"
# define _DOOR_DIR_NAME "DOOR"
# define _PISTOL_DIR_NAME "PISTOL"
# define _ARM_DIR_NAME "ARM"
# define _SHOTGUN_DIR_NAME "SHOTGUN"

# define _TEXTURE_COUNT 5
# define _SPRITE_COUNT 6

enum e_sprites
{
	_E_DOOR,
	_E_WALLS,
	_E_PISTOL,
	_E_ARM,
	_E_SHOTGUN,
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

typedef struct s_image
{
	void	*mlx;	// Pointer to mlx instance
	void	*img;
	char	*buffer;
	int		depth;
	int		line_size;
	int		width;
	int		height;
	int		endian;
	int		depth8;
}	t_image;

typedef struct s_sprite
{
	t_image	*img_arr;
	int		len;
}	t_sprite;

typedef struct s_sprite	t_images;

typedef struct s_texture_pointers
{
	t_image		*textures_arr[_TEXTURE_COUNT];
	char		*tex_names[_TEXTURE_COUNT];
	t_sprite	*sprites[_SPRITE_COUNT];
	char		*sp_names[_SPRITE_COUNT];
}	t_texture_pointers;

typedef struct s_animation
{
	t_sprite	*sprite;
	int			frame_count;
	int			current_frame;
	double		animation_timer;
	bool		is_playing;
	double		tp_frame;
	double		time;
}	t_animation;

typedef struct s_textures
{
	t_images			walls;
	t_sprite			weapons[WEAPONS_COUNT];
	t_image				ceiling;
	t_image				floor;
	t_image				portal_in;
	t_image				portal_out;
	t_sprite			door;
	t_texture_pointers	tp;
}	t_textures;

typedef struct s_image	t_frame_buf;

#endif
