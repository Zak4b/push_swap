/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:39:54 by asene             #+#    #+#             */
/*   Updated: 2024/12/17 14:43:24 by asene            ###   ########.fr       */
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

