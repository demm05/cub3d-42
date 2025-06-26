/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:01:49 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/24 12:50:58 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_PRIVATE_H
# define RAYCASTER_PRIVATE_H

# include "cube.h"

void	ray_set_wall_prop(t_engine *eng, t_ray *ray);
void	ray_set_floor_prop(t_engine *eng, t_ray *ray);

void	perform_dda(t_ray *ray, t_engine *eng);

#endif
