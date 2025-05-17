/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:17:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:17:03 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define WIDTH 1280
# define HEIGHT 720
# define WINDOW_NAME "CUB3D"
# define ENABLE_RESIZE 0
# define DISABLE_AUTOREPEAT_KEY 1
# define PLAYER_2D_SIZE 50
# define MAX_DELTA_TIME 1.0 / 15.0

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/include/libft.h"

# include "types.h"

# ifndef WINDOW_H
#  include "../src/window/window.h"
# endif

# ifndef GAME_H 
#  include "../src/game/game.h"
# endif

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
