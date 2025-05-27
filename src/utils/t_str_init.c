/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:49:47 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/24 15:04:22 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

t_string	*t_str_init(const char *value)
{
	t_string	*str;

	if (!value)
		return (NULL);
	str = ft_calloc(sizeof(t_string), 1);
	if (!str)
		return (NULL);
	str->len = ft_strlen(value);
	str->str = ft_strdup(value);
	if (!str->str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
