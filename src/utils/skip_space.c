/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:37:58 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/24 17:08:16 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

int	skip_space(char *str)
{
	int	space;

	space = 0;
	if (!str)
		return (space);
	while (str[space] && str[space] == ' ')
		space++;
	return (space);
}
