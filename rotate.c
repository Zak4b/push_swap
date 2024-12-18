/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:17:15 by asene             #+#    #+#             */
/*   Updated: 2024/12/18 13:00:33 by asene            ###   ########.fr       */
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
	*s = first;
}

/*
ra
Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
*/
void	rotate_a(t_vars *vars)
{
	rotate(&vars->a);
	ft_putendl_fd("ra", 1);
}

/*
rb
Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
*/
void	rotate_b(t_vars *vars)
{
	rotate(&vars->b);
	ft_putendl_fd("rb", 1);
}

void	rotate_both(t_vars *vars)
{
	rotate(&vars->a);
	rotate(&vars->b);
	ft_putendl_fd("rr", 1);
}
