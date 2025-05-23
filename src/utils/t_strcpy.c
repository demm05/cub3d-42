/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:14:43 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/23 14:27:31 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_string	*t_strcpy(t_string *src)
{
	if (!src)
		return (NULL);
	return (t_str_init(src->str));
}

t_string	*t_strlcpy(t_string *src, size_t size)
{
	t_string	*new;

	new = ft_calloc(sizeof(t_string), 1);
	if (!new)
		return (NULL);
	new->str = malloc(sizeof(char) * size);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	ft_strlcpy(new->str, src->str, size);
	new->len = size;
	return (new);
}
