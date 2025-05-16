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
# define DO_KEY_AUTOREPEAT 1

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stdio.h>
# include <stdlib.h>

# include "libft/include/libft.h"

# include "types.h"

# ifndef WINDOW_H
#  include "../src/window/window.h"
# endif

#endif
