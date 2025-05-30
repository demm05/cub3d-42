/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:40:23 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/28 14:40:46 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

size_t	split_len(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return (i);
	while (split[i])
		i++;
	return (i);
}
