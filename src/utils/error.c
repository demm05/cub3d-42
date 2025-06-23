/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:30:40 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 13:30:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"
#include <stdarg.h>

int	error_log(const char *format, ...)
{
	va_list	args;
	
	va_start(args, format);
	ft_fprintf(STDERR_FILENO, RED"ERROR"RESET": ");
	ft_vfprintf(STDERR_FILENO, format, args);
	va_end(args);
	return (FAILURE);
}
