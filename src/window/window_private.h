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

# include "mlx.h"
# include "window.h"

t_mlx_data	*create_window(t_window *win);
void		mlx_free(t_mlx_data **arg);

#endif
