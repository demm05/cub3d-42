/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:56:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 11:50:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# include "cube.h"

typedef struct s_world
{
	int	width;
	int	height;
}   t_world;

#endif
