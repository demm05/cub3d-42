/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:27:49 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/23 14:30:44 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	t_str_free(void *t_str)
{
	t_string	*str;

	str = (t_string *)t_str;
	if (!str)
		return ;
	if (str->str)
	{
		free(str->str);
	}
	str->len = 0;
	free(str);
}
