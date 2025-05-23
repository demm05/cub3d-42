/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:59:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 13:10:37 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "cube.h"

typedef struct s_camera
{
    double  x;
    double  y;
    double  move_speed;
    double  rotation_speed;
}   t_camera;

#endif