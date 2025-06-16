/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:25:52 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/16 16:42:47 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PRIVATE_H
# define UTILS_PRIVATE_H

# include "cube.h"

bool	flood_fill(t_map *map, int y, int x);
t_map	*coppy_map(t_map *map);

#endif