/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:38:25 by asene             #+#    #+#             */
/*   Updated: 2024/12/24 10:35:33 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **from, t_stack **to)
{
	t_stack	*first;

	if (!*from)
		return (0);
	first = (*from)->next;
	if (first)
		first->prev = NULL;
	else
		first = NULL;
	stack_add_front(to, *from);
	*from = first;
	return (1);
}

void	push_to_a(t_vars *vars)
{
	if (push(&vars->b, &vars->a))
	{
		vars->count_a++;
		vars->count_b--;
	}
	if (vars->display_instructions)
		ft_putendl_fd("pa", 1);
}

void	push_to_b(t_vars *vars)
{
	if (push(&vars->a, &vars->b))
	{
		vars->count_b++;
		vars->count_a--;
	}
	if (vars->display_instructions)
		ft_putendl_fd("pb", 1);
}
