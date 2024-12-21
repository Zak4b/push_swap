/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:15:57 by asene             #+#    #+#             */
/*   Updated: 2024/12/21 14:59:59 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int n)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->prev = NULL;
	new_stack->next = NULL;
	new_stack->n = n;
	return (new_stack);
}

void	stack_clear(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	if ((*stack)->next)
		stack_clear(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*first;

	if (*stack == NULL)
	{
		*stack = new;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	first = stack_first(*stack);
	first->prev = new;
	new->next = first;
	*stack = new;
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	last = stack_last(*stack);
	last->next = new;
	new->prev = last;
}

int	stack_insert_sort(t_stack **stack, t_stack *new)
{
	t_stack	*s;

	if (*stack == NULL)
		return (*stack = new, 1);
	if (new->n < (*stack)->n)
		return (stack_add_front(stack, new), 1);
	s = *stack;
	while (s)
	{
		if (new->n > s->n && (s->next == NULL || s->next->n > new->n))
		{
			new->next = s->next;
			if (s->next)
				s->next->prev = new;
			new->prev = s;
			s->next = new;
			return (1);
		}
		if (s->next == NULL)
			break ;
		s = s->next;
	}
	return (0);
}
