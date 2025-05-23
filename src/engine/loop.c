/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:24:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 12:37:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_private.h"
#include "render.h"
#include <math.h>

# define PI 3.1415926535

int worldMap[MAP_HEIGHT][MAP_WIDTH] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

inline void	cast_ray(t_engine *eng, t_camera *cam)
{
	double	rayDirX;
	double	rayDirY;
	double	cameraX;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		x;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit = 0; //was there a wall hit?
	int		side; //was a NS or a EW wall hit?
	bool	once = 0;
	int	lineHeight;
	int	drawStart;
	int	drawEnd = 0;
	int color = 0;

	x = 0;
	while (x < eng->window.width)
	{
		cameraX = 2 * x / (double)eng->window.width - 1;
		rayDirX = cam->dir.x + cam->plane.x * cameraX;
		rayDirY = cam->dir.y + cam->plane.y * cameraX;
		mapX = (int)cam->pos.x;
		mapY = (int)cam->pos.y;
		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cam->pos.x- mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cam->pos.x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cam->pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cam->pos.y) * deltaDistY;
		}
		hit = 0;
		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapY][mapX] > 0)
				hit = 1;
		}
		if (!side)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;
		lineHeight = (int)(eng->window.height / perpWallDist);
		drawStart = -lineHeight / 2 + eng->window.height / 2;
		if(drawStart < 0) drawStart = 0;
		drawEnd = lineHeight / 2 + eng->window.height / 2;
		if(drawEnd >= eng->window.height) drawEnd = eng->window.height - 1;
		color = 0xFFF000;
		if (side)
			color = color / 2;
		// printf("%d %d %d %d\n", x, lineHeight, drawStart, drawEnd);
		draw_vert_line(&eng->main_buffer, x, 0, drawStart, 0x00FFF0);
		draw_vert_line(&eng->main_buffer, x, drawStart, drawEnd, color);
		draw_vert_line(&eng->main_buffer, x, drawEnd, eng->window.height, 0x808080);
		x++;
	}
}

int	engine_loop(t_engine *eng)
{
	static int x;

	if (x >= eng->window.width)
		x = 0;
	buffer_clear(&eng->main_buffer);
	update_movements(&eng->camera, &eng->input);
	cast_ray(eng, &eng->camera);
	// draw_vert_line(&eng->main_buffer, x++, 500, 510, 0xFF00);
	buffer_flash(&eng->main_buffer, &eng->window, 0, 0);
	usleep(100);
	return (0);
}
