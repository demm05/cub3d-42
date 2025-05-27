/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdell_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:13:46 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/24 15:22:28 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

void	lstdell_front(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_head;

	if (!lst || !*lst)
		return ;
	tmp_head = (*lst)->next;
	ft_lstdelone(*lst, del);
	*lst = tmp_head;
}
