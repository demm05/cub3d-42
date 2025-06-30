/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:28:52 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 13:28:53 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "cube.h"

typedef struct s_entity
{
	int			health;
	float		move_speed;
	t_animation	*weapon;
	t_animation	weapons[WEAPONS_COUNT];
}	t_entity;

#endif
