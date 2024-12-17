/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:17:15 by asene             #+#    #+#             */
/*   Updated: 2024/12/17 15:05:11 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*new_last;

	last = lst_last(*s);
	new_last = last->prev;
	last->next = *s;
	last->prev = NULL;
	(*s)->prev = last;
	new_last->next = NULL;
}

/*
rra
Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
*/
void	rev_rotate_a(t_stack **a)
{
	rev_rotate(a);
	ft_putendl_fd("rra", 1);
}

/*
rrb
Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
*/
void	rev_rotate_b(t_stack **b)
{
	rev_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	rev_rotate_both(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putendl_fd("rrr", 1);
}
