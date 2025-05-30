/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:26:26 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/30 12:28:22 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

bool	flood_fill(t_map *map, int y, int x)
{
	// Вийшли за межі карти — карта відкрита!
	if (y < 0 || y >= map->height || x < 0 || x >= map->width)
		return (0);
	// Якщо вже "стіна" або вже перевірена — ОК
	if (map->matrix[y][x] == '1' || map->matrix[y][x] == 'V')
		return (1);
	// Позначаємо як відвідану (V — visited)
	map->matrix[y][x] = 'V';
	// Перевіряємо всі напрямки
	if (!flood_fill(map, y + 1, x)
		|| !flood_fill(map, y - 1, x)
		|| !flood_fill(map, y, x + 1)
		|| !flood_fill(map, y, x - 1))
		return (0); // Знайшли "дірку" (не закрито)
	return (1); // Все ОК
}