/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:08:07 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/30 15:19:13 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

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

#endif