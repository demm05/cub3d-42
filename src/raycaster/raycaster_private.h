/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:01:49 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 10:40:31 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_PRIVATE_H
# define RAYCASTER_PRIVATE_H

# include "cube.h"

void	cast_ray(t_engine *eng, t_ray *ray, int h, int w);

#endif
