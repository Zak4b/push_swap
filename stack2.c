/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:39:54 by asene             #+#    #+#             */
/*   Updated: 2024/12/21 15:16:46 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_first(t_stack *stack)
{
	if (stack)
		while (stack->prev)
			stack = stack->prev;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	if (stack)
		while (stack->next)
			stack = stack->next;
	return (stack);
}

int	stack_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_stack *s)
{
	while (s && (!s->next || (s->next && s->n < s->next->n)))
		s = s->next;
	return (s == NULL);
}

void	print_stack(t_stack *s)
{
	while (s)
	{
		ft_printf("%d -> ", s->n);
		s = s->next;
	}
	ft_putstr_fd("NULL\n", 1);
}
