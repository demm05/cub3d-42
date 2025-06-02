/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:17:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/30 15:09:58 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define INITIAL_WINDOW_WIDTH 1580
# define INITIAL_WINDOW_HEIGHT 1000
# define WINDOW_TITLE "CUBE 3D"
# define MAX_DELTA_TIME 1.0 / 15.0 // 60 limit movement to FPS

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

# ifdef ENABLE_CUSTOM_INLINING
#  ifdef __GNUC__ // For GCC/Clang
#   define MAYBE_INLINE __attribute__((always_inline)) inline
#  elif defined(_MSC_VER) // For MSVC
#   define MAYBE_INLINE __forceinline
#  else // Standard C inline hint
#   define MAYBE_INLINE inline
#  endif
# else
#  define MAYBE_INLINE // Expands to nothing, so function is "normal"
# endif

#endif
