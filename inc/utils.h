/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:55:39 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/22 12:35:33 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cube.h"

bool	init_mlx_and_window(t_engine *eng);
void	mlx_enable_window_resize(void *mlx, t_window *window);

#endif
