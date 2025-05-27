/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:55:39 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/05/24 15:14:20 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cube.h"

/*----------------String----------------*/

typedef struct string
{
	char	*str;
	size_t	len;
}	t_string;

t_string	*t_str_init(const char *value);

size_t		t_strappend_cstr(t_string *dest, const char *src);
size_t		t_strappend_t_str(t_string *dest, t_string *src);

t_string	*t_strcpy(t_string *src);
t_string	*t_strlcpy(t_string *src, size_t size);

int			t_strcmp(t_string *str1, t_string *str2);

void		t_str_free(void *t_str);

/*----------------End string----------------*/

void		free_str_arr(char **arr);
void		lstdell_front(t_list **lst, void (*del)(void *));

bool		init_mlx_and_window(t_engine *eng);
void		mlx_enable_window_resize(void *mlx, t_window *window);
int			input_event_resize(t_engine *eng);

#endif
