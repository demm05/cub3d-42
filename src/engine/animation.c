/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:36:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 16:54:48 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"

void	animation_update(t_animation *anim, double delta)
{
	if (!anim || !anim->is_playing)
		return ;
	anim->animation_timer += delta;
	if (anim->animation_timer < anim->tp_frame)
		return ;
	while (anim->animation_timer >= anim->tp_frame)
	{
		anim->current_frame++;
		if (anim->current_frame >= anim->frame_count)
		{
			anim->current_frame = 0;
			anim->is_playing = 0;
			return ;
		}
		anim->animation_timer -= anim->tp_frame;
	}
}

void	animation_start(t_animation *anim)
{
	if (!anim || anim->is_playing)
		return ;
	anim->animation_timer = 0;
	anim->current_frame = 0;
	anim->is_playing = true;
}

void	animations_update_all(t_engine *eng)
{
	animation_update(eng->player.weapon, eng->timing.delta_time);
}

t_image	*animation_get_image(t_animation *anim)
{
	return (&anim->sprite->img_arr[anim->current_frame]);
}
