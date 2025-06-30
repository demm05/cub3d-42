/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:17:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 14:59:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define INITIAL_WINDOW_WIDTH 1580
# define INITIAL_WINDOW_HEIGHT 1000
# define WINDOW_TITLE "CUBE 3D"
# define MAX_DELTA_TIME 0.06f

# define ENABLE_RESIZE 1
# define DISABLE_AUTOREPEAT_KEY 1

# define FOV 0.66
# define ENABLE_FOG 1
# define FOG_DISTANCE 22.0

# define SUCCESS 1
# define FAILURE 0
# define MEM_ALLOCATE_ERR ": fail to allocate memory"

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"

# include "types.h"
# include "assets.h"
# include "entity.h"
# include "menu.h"
# include "minimap.h"
# include "render.h"
# include "parser.h"
# include "input.h"
# include "camera.h"
# include "raycaster.h"
# include "door.h"
# include "engine.h"
# include "utils.h"
# include "text.h"

# include "ft_color_utils.h"

void	set_defaults(t_engine *eng);

#endif
