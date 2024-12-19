/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:15:57 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 19:49:37 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new(int n)
{
	t_stack	*new_list;

	new_list = malloc(sizeof(t_stack));
	if (new_list == NULL)
		return (NULL);
	new_list->prev = NULL;
	new_list->next = NULL;
	new_list->n = n;
	return (new_list);
}

void	lst_clear(t_stack **lst)
{
	if (!lst || !(*lst))
		return ;
	if ((*lst)->next)
		lst_clear(&((*lst)->next));
	free(*lst);
	*lst = NULL;
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		return ;
	}
	first = lst_first(*lst);
	first->prev = new;
	new->next = first;
	*lst = new;
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		return ;
	}
	last = lst_last(*lst);
	last->next = new;
	new->prev = last;
}

int	lst_insert_sort(t_stack **lst, t_stack *new)
{
	t_stack	*l;

	if (*lst == NULL)
		return (*lst = new, 1);
	if (new->n < (*lst)->n)
		return (lstadd_front(lst, new), 1);
	l = *lst;
	while (l)
	{
		if (new->n > l->n && (l->next == NULL || l->next->n > new->n))
		{
			new->next = l->next;
			if (l->next)
				l->next->prev = new;
			new->prev = l;
			l->next = new;
			return (1);
		}
		if (l->next == NULL)
			break ;
		l = l->next;
	}
	return (0);
}
