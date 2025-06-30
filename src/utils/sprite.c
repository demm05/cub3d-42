/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:41:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 15:17:07 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

inline t_image	*sprite_get_img(t_images *sp, int i)
{
	return (&sp->img_arr[i % sp->len]);
}
