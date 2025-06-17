/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:55:39 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/10 12:44:29 by ogrativ          ###   ########.fr       */
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

size_t		split_len(char **split);

void		free_str_arr(char **arr);
void		lstdell_front(t_list **lst, void (*del)(void *));

/**
 * @brief Check if a file path ends with the expected file extension.
 * 
 * @note This function assumes that `ext` includes the dot (e.g., ".xpm"),
 * and it uses the last '.' in the string to detect the extension.
 * It is intended for use in parsers or controlled file input cases.
 * If mode equal 1 function will print error message
 * 
 * @param path The file path to check.
 * @param ext The expected extension (e.g., ".xpm").
 * @param mode The mode of use for print error message
 * @return true if the extension matches, false otherwise.
 */
bool		check_file_ext(const char *path, const char *ext, bool mode);

bool		check_map(t_map *map);

bool		init_mlx_and_window(t_engine *eng);
void		mlx_enable_window_resize(void *mlx, t_window *window);
int			input_event_resize(t_engine *eng);

int			sort_str_lst(t_list **lst);

int			map_get(t_map *map, int x, int y);
void		map_set(t_map *map, int x, int y, int c);
t_image		*sprite_get_img(t_images *sp, int i);
#endif
