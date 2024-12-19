/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:15:20 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 11:30:06 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	elem_by_pos(t_stack *s, int pos)
{
	int		i;

	i = 0;
	while (s && i++ < pos)
		s = s->next;
	return (s->n);
}

void	sort_3(t_vars *vars)
{
	if (vars->a->n > vars->a->next->n && vars->a->n > vars->a->next->next->n)
		rotate_a(vars);
	else if (vars->a->next->n > vars->a->n && vars->a->next->n > vars->a->next->next->n)
		rev_rotate_a(vars);
	if (vars->a->n > vars->a->next->n)
		swap_a(vars);
}

void	sort_stack(t_vars *vars)
{
	int	i;

	if (is_sorted(vars->a))
		return ;
	if (vars->size == 2)
		return (swap_a(vars));
	else if (vars->size == 3)
		return (sort_3(vars));
	vars->n_piv = 14;
	vars->pivots = ft_calloc(vars->n_piv, sizeof(int));
	i = 0;
	while (i < vars->n_piv)
	{
		vars->pivots[i] = elem_by_pos(vars->sorted, (vars->size * i / vars->n_piv));
		i++;
	}
	i = 0;
}
/*
int	f_nearest(t_stack *stack, int min, int max)
{
	int	highest;
	int	lowest;

	highest = f_pos(stack->first, f_high_low(stack, min, max, 0));
	lowest = f_pos(stack->first, f_high_low(stack, min, max, 1)) + 1;
	if ((highest < reverse_h && highest < reverse_l)
		|| (lowest < reverse_h && lowest < reverse_l))
		return (1);
	return (0);
}
*/