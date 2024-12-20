/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:17:15 by asene             #+#    #+#             */
/*   Updated: 2024/12/20 10:51:15 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*first;

	if (lst_size(*s) <= 1)
		return ;
	first = (*s)->next;
	first->prev = NULL;
	(*s)->prev = lst_last(*s);
	(*s)->prev->next = *s;
	(*s)->next = NULL;
	*s = first;
}

void	rotate_a(t_vars *vars)
{
	rotate(&vars->a);
	ft_putendl_fd("ra", 1);
}

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
