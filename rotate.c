/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:17:15 by asene             #+#    #+#             */
/*   Updated: 2024/12/17 14:52:38 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*first;

	first = (*s)->next;
	first->prev = NULL;
	(*s)->prev  = lst_last(*s);
	(*s)->prev->next = *s;
	(*s)->next = NULL;

}

/*
ra
Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
*/
void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

/*
rb
Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
*/
void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
