#include "engine_private.h"

MAYBE_INLINE void	animation_update(t_animation *anim, double delta)
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

MAYBE_INLINE void	animation_start(t_animation *anim)
{
	if (!anim || anim->is_playing)
		return;
	anim->animation_timer = 0;
	anim->current_frame = 0;
	anim->is_playing = true;
}

MAYBE_INLINE void	animation_init_sprite(t_animation *anim)
{
	anim->current_frame = 0;
	anim->animation_timer = 0;
	anim->is_playing = false;
	anim->frame_count = anim->sprite->len;
	anim->tp_frame = anim->time / (float)anim->frame_count;
}

MAYBE_INLINE void	animation_change_sprite(t_animation *anim, t_sprite *sp)
{
	if (!anim)
		return ;
	anim->sprite = sp;
	animation_init_sprite(anim);
}

MAYBE_INLINE void	animation_set_sprite(t_animation *anim, t_sprite *sp, double time)
{
	if (!anim)
		return ;
	anim->sprite = sp;
	anim->time = time;
	animation_init_sprite(anim);
}

MAYBE_INLINE void	animation_set_time(t_animation *anim, float time)
{
	if (!anim)
		return;
	anim->time = time;
	animation_init_sprite(anim);
}

MAYBE_INLINE void	animations_init(t_engine *eng)
{
	eng->player.weapon = &eng->player.weapons[0];
	animation_set_sprite(&eng->player.weapons[0], &eng->textures.weapons[0], 0.2);
	animation_set_sprite(&eng->player.weapons[1], &eng->textures.weapons[1], 0.6);
	animation_set_sprite(&eng->player.weapons[2], &eng->textures.weapons[2], 0.9);
}

MAYBE_INLINE void	animations_update_all(t_engine *eng)
{
	animation_update(eng->player.weapon, eng->timing.delta_time);
}

MAYBE_INLINE t_image	*animation_get_image(t_animation *anim)
{
	return (&anim->sprite->img_arr[anim->current_frame]);
}
