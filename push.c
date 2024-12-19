/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:38:25 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 19:50:39 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*first;

	if (!*from)
		return ;
	first = (*from)->next;
	if (first)
		first->prev = NULL;
	else
		first = NULL;
	lstadd_front(to, *from);
	*from = first;
}

/*
pa
Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
*/
void	push_to_a(t_vars *vars)
{
	push(&vars->b, &vars->a);
	ft_putendl_fd("pa", 1);
}

/*
pb
Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
*/
void	push_to_b(t_vars *vars)
{
	push(&vars->a, &vars->b);
	ft_putendl_fd("pb", 1);
}