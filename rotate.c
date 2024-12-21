/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:17:15 by asene             #+#    #+#             */
/*   Updated: 2024/12/21 15:18:14 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*new_first;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	new_first = (*s)->next;
	new_first->prev = NULL;
	(*s)->prev = stack_last(*s);
	(*s)->prev->next = *s;
	(*s)->next = NULL;
	*s = new_first;
}

void	rotate_a(t_vars *vars)
{
	if (vars->count_a > 1)
		rotate(&vars->a);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_vars *vars)
{
	if (vars->count_b > 1)
		rotate(&vars->b);
	ft_putendl_fd("rb", 1);
}

void	rotate_both(t_vars *vars)
{
	rotate(&vars->a);
	rotate(&vars->b);
	ft_putendl_fd("rr", 1);
}
