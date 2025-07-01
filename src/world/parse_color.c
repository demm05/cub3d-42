/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:33:13 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/01 12:52:05 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_private.h"

static bool	is_rgb(int color)
{
	if (color >= 0 && color < 256)
	{
		return (1);
	}
	return (0);
}

static bool	is_number(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static bool	check_color(char **numbers, size_t len)
{
	size_t	i;
	char	*number;
	int		space;

	i = 0;
	number = NULL;
	while (i < len)
	{
		space = skip_space(numbers[i]);
		number = numbers[i] + space;
		if (!number || ft_strlen(number) > 3 || !is_number(number))
		{
			ft_putendl_fd(RED "Error" RESET
				": Invalid color format", STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_color(const char *path)
{
	char	**numbers;
	t_rgb	rgb;
	size_t	len;

	numbers = ft_split((char *)path, ",");
	if (!numbers)
		return (-1);
	len = split_len(numbers);
	if (len != 3 || !check_color(numbers, len))
	{
		free_str_arr(numbers);
		ft_putstr_fd(RED "Error" RESET
			": Incorrect RGB format\n", STDERR_FILENO);
		return (-1);
	}
	rgb.red = ft_atoi(numbers[0]);
	rgb.green = ft_atoi(numbers[1]);
	rgb.blue = ft_atoi(numbers[2]);
	free_str_arr(numbers);
	if (is_rgb(rgb.blue) && is_rgb(rgb.green) && is_rgb(rgb.red))
		return ((rgb.red << 16) | (rgb.green << 8) | rgb.blue);
	ft_putstr_fd(RED "Error" RESET
		": Incorrect RGB format: Values must be beetwen 0-255\n",
		STDERR_FILENO);
	return (-1);
}
