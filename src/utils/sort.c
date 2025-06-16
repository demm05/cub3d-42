/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:36:52 by ogrativ           #+#    #+#             */
/*   Updated: 2025/06/09 17:15:15 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_private.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
	{
		return ;
	}
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

static void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (b == NULL || *b == NULL)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
}

static int	pi(t_list **b, t_list **a, int pos)
{
	int		i;
	t_list	*current;
	t_list	*insert;

	if (!a || !*a)
		return (-1);
	if (!b || !*b || pos <= 0)
		return (pa(b, a), 0);
	if (pos >= ft_lstsize(*b))
	{
		pa(b, a);
		return (rotate(b), 0);
	}
	current = *b;
	i = 1;
	while (i < pos && current->next)
	{
		current = current->next;
		i++;
	}
	insert = *a;
	*a = insert->next;
	insert->next = current->next;
	current->next = insert;
	return (0);
}

int	sort_str_lst(t_list **lst)
{
	t_list	*sorted;
	t_list	*cur;
	int		pos;

	if (!lst || !*lst)
		return (-1);
	sorted = NULL;
	while (*lst)
	{
		cur = sorted;
		pos = 0;
		while (cur && ft_strcmp(cur->content, (*lst)->content) <= 0)
		{
			cur = cur->next;
			pos++;
		}
		pi(&sorted, lst, pos);
	}
	*lst = sorted;
	return (0);
}
