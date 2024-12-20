/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:17:15 by asene             #+#    #+#             */
/*   Updated: 2024/12/20 10:50:38 by asene            ###   ########.fr       */
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
	*s = last;
}

void	rev_rotate_a(t_vars *vars)
{
	rev_rotate(&vars->a);
	ft_putendl_fd("rra", 1);
}

void	rev_rotate_b(t_vars *vars)
{
	rev_rotate(&vars->b);
	ft_putendl_fd("rrb", 1);
}

void	rev_rotate_both(t_vars *vars)
{
	rev_rotate(&vars->a);
	rev_rotate(&vars->b);
	ft_putendl_fd("rrr", 1);
}
