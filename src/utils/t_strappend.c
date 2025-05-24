/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:57:51 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/23 14:26:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	t_strappend_cstr(t_string *dest, const char *src)
{
	char	*new_line;
	size_t	len;

	if (!dest)
		return (0);
	if (!src)
		return (dest->len);
	len = dest->len + ft_strlen(src) + 1;
	new_line = malloc(sizeof(char) * len);
	if (!new_line)
		return (dest->len);
	ft_strlcpy(new_line, dest->str, dest->len);
	ft_strlcat(new_line, src, len);
	free(dest->str);
	dest->str = new_line;
	dest->len = len;
	return (len);
}

size_t	t_strappend_t_str(t_string *dest, t_string *src)
{
	char	*new_line;
	size_t	len;

	if (!dest)
		return (0);
	if (!src)
		return (dest->len);
	len = dest->len + src->len + 1;
	new_line = malloc(sizeof(char) * len);
	if (!new_line)
		return (dest->len);
	ft_strlcpy(new_line, dest->str, dest->len);
	ft_strlcat(new_line, src->str, len);
	free(dest->str);
	dest->str = new_line;
	dest->len = len;
	return (len);
}
