/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:17:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 13:12:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define INITIAL_WINDOW_WIDTH 1280
# define INITIAL_WINDOW_HEIGHT 720
# define WINDOW_TITLE "CUBE 3D"

# define ENABLE_RESIZE 0
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

# include "render.h"
# include "assets.h"
# include "camera.h"
# include "world.h"
# include "input.h"
# include "engine.h"
# include "raycaster.h"
# include "utils.h"

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
