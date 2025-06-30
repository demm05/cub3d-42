#include "render_private.h"

MAYBE_INLINE void	render_weapon(t_engine *eng)
{	
	t_image	*texture;
	t_point	scaled_size;
	t_point	screen_pos;
	int		color;

	texture = animation_get_image(eng->player.weapon);
	if (!texture || !texture->img)
		return ;

	scaled_size.x = eng->window.width * 0.2;
	// Calculate scaled height to maintain the original aspect ratio
	scaled_size.y = (int)((double)scaled_size.x * ((double)texture->height / texture->width));

	// 2. Determine the starting position on the screen (bottom-centered)
	screen_pos.x = (eng->window.width - scaled_size.x) / 2;
	screen_pos.y = eng->window.height - scaled_size.y;

	// 3. Loop over the target area on the screen
	for (int y = 0; y < scaled_size.y; y++)
	{
		for (int x = 0; x < scaled_size.x; x++)
		{
			// 4. Map the screen coordinate back to the original texture coordinate
			int tex_x = (int)((double)x / scaled_size.x * texture->width);
			int tex_y = (int)((double)y / scaled_size.y * texture->height);
			color = get_pixel_color(texture, tex_x, tex_y);
			if (!((color >> 24) & 0xFF))
				draw_pixel(&eng->main_buffer, screen_pos.x + x, screen_pos.y + y, color);
		}
	}
}
