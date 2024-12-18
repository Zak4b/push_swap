/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:39:54 by asene             #+#    #+#             */
/*   Updated: 2024/12/18 14:33:49 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_first(t_stack *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_stack	*lst_last(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	lst_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->prev;
		i++;
	}
	return (i);
}

int	is_sorted(t_stack *s)
{
	while (s && (!s->next || (s->next && s->n < s->next->n)))
		s = s->next;
	return (s == NULL);
}
