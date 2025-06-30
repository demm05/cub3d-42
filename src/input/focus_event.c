/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:05:12 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/30 14:14:14 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_private.h"

int	input_focus_in(t_engine *eng)
{
	(void)eng;
	return (0);
}

int	input_focus_out(t_engine *eng)
{
	ft_bzero(&eng->input, sizeof(t_input));
	return (0);
}
