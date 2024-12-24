/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:17:15 by asene             #+#    #+#             */
/*   Updated: 2024/12/24 10:35:33 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*new_last;

	last = stack_last(*s);
	new_last = last->prev;
	last->next = *s;
	last->prev = NULL;
	(*s)->prev = last;
	new_last->next = NULL;
	*s = last;
}

void	rev_rotate_a(t_vars *vars)
{
	if (vars->count_a > 1)
		rev_rotate(&vars->a);
	if (vars->display_instructions)
		ft_putendl_fd("rra", 1);
}

void	rev_rotate_b(t_vars *vars)
{
	if (vars->count_b > 1)
		rev_rotate(&vars->b);
	if (vars->display_instructions)
		ft_putendl_fd("rrb", 1);
}

void	rev_rotate_both(t_vars *vars)
{
	rev_rotate(&vars->a);
	rev_rotate(&vars->b);
	if (vars->display_instructions)
		ft_putendl_fd("rrr", 1);
}
