/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:17:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 14:09:17 by ogrativ          ###   ########.fr       */
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

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"

# include "vector.h"
# include "render.h"
# include "assets.h"
# include "world.h"
# include "input.h"
# include "camera.h"
# include "raycaster.h"
# include "engine.h"
# include "utils.h"

# include "ft_color_utils.h"

void	set_defaults(t_engine *eng);

#endif
