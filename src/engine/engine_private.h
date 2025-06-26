/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:58:25 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 10:12:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_PRIVATE_H
# define ENGINE_PRIVATE_H

# include "cube.h"

void	animation_update(t_animation *anim, double delta);
void	animations_update_all(t_engine *eng);
void	animations_init(t_engine *eng);

#endif
