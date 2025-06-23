/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:23 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:30:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_private.h"

static inline char	*static_str_from_int(unsigned int num)
{
	static char		s[12];
	char			*ptr;

	ptr = &s[11];
	*ptr = 0;
	while (1)
	{
		*--ptr = (num % 10) + '0';
		num /= 10;
		if (num < 1)
			break ;
	}
	return (ptr);
}

MAYBE_INLINE void	text_put_int(t_engine *eng, t_point start, t_ui num, unsigned int color)
{
	if (!eng)
		return ;
	text_put_str(eng, start, static_str_from_int(num), color);
}
