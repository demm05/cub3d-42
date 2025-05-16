/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:15:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/16 16:15:56 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cube.h"

int		game_loop(t_cube *cube);
void	game_hook(t_cube *cube);

typedef struct s_FPS_Counter {
    long long frame_count;
    double fps;
    double update_interval_seconds;
    struct timespec last_time;
} FPS_Counter;

// Function declarations

/**
 * @brief Initializes the FPS counter for Linux.
 *
 * @param counter Pointer to the FPS_Counter struct to initialize.
 * @param update_interval_seconds How often (in seconds) to recalculate the FPS.
 * @return int 0 on success, -1 on error (e.g., timer initialization failed).
 */
int fps_counter_init(FPS_Counter* counter, double update_interval_seconds);

/**
 * @brief Call this function once per rendered frame.
 *
 * It increments the frame count and, if the update interval has passed,
 * recalculates the FPS.
 *
 * @param counter Pointer to the FPS_Counter struct.
 * @return int 1 if FPS was updated in this call, 0 otherwise.
 */
int fps_counter_tick(FPS_Counter* counter);

/**
 * @brief Gets the most recently calculated FPS.
 *
 * @param counter Pointer to the FPS_Counter struct.
 * @return double The current FPS value.
 */
double fps_counter_get_fps(const FPS_Counter* counter);

#endif
