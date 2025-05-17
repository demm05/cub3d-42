/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:16:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/15 17:16:35 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_PRIVATE_H
# define WINDOW_PRIVATE_H

# define FPS_COUNTER_MSC_UPDATE 1000

# include "mlx.h"
# include "window.h"

bool	create_window(void *mlx, t_window *win);
void	mlx_free(t_cube *cube);

#endif
