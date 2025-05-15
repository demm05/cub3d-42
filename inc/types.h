/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:17:05 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:17:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_mlx_data	t_mlx_data;

typedef struct s_window
{
	unsigned int	width;
	unsigned int	height;
}	t_window;

typedef struct s_cube
{
	t_window	window;
	t_mlx_data	*mlx;
}	t_cube;

#endif
