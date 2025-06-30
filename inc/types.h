/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:08:07 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/30 13:28:36 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_vec2_double
{
	double	x;
	double	y;
}	t_vec2_double;

typedef struct s_vec2_int
{
	int	x;
	int	y;
}	t_vec2_int;

typedef struct s_vec2_int	t_point;
typedef struct s_engine		t_engine;
typedef unsigned int		t_ui;
typedef struct s_minimap	t_minimap;
typedef struct s_freetype	t_freetype;

# define FF ft_fprintf

#endif
