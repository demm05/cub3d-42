/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:31:01 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/23 14:34:45 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	t_strcmp(t_string *str1, t_string *str2)
{
	if (!str1 && !str2)
		return (0);
	if (!str1)
		return (-1);
	if (!str2)
		return (1);
	if (str1->len != str2->len)
		return (str1->len - str2->len);
	return (ft_strcmp(str1->str, str2->str));
}
