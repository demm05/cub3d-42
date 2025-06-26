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
