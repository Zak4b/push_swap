/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:38:25 by asene             #+#    #+#             */
/*   Updated: 2024/12/17 14:13:45 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack *first;

	first = (*from)->next;
	first->prev = NULL;
	lstadd_front(to, *from);
	*from = first;
}

/*
pa
Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
*/
void	push_to_a(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

/*
pb
Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
*/
void	push_to_b(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}