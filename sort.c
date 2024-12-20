/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:15:20 by asene             #+#    #+#             */
/*   Updated: 2024/12/20 10:59:51 by asene            ###   ########.fr       */
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
	int	elems[3];

	elems[0] = elem_by_pos(vars->a, 0);
	elems[1] = elem_by_pos(vars->a, 1);
	elems[2] = elem_by_pos(vars->a, 2);
	if (elems[0] > elems[1] && elems[0] > elems[2])
		rotate_a(vars);
	else if (elems[1] > elems[0] && elems[1] > elems[2])
		rev_rotate_a(vars);
	if (elem_by_pos(vars->a, 0) > elem_by_pos(vars->a, 1))
		swap_a(vars);
}

void	sort_4_to_5(t_vars *vars)
{
	int	current;
	int	i;

	i = vars->size - 3;
	while (i > 0)
	{
		current = vars->a->n;
		if (current == vars->sorted[0] || ((vars->size == 5)
				&& current == vars->sorted[1]))
		{
			push_to_b(vars);
			i--;
		}
		else
			rotate_a(vars);
	}
	sort_3(vars);
	if (vars->size == 5)
	{
		if (vars->b->n < vars->b->next->n)
			swap_b(vars);
		push_to_a(vars);
	}
	push_to_a(vars);
}

void	sort_stack(t_vars *vars)
{
	if (is_sorted(vars->a))
		return ;
	if (vars->size == 2)
		return (swap_a(vars));
	else if (vars->size == 3)
		return (sort_3(vars));
	else if (vars->size <= 5)
		return (sort_4_to_5(vars));
	else if (vars->size < 100)
		vars->n_group = 2;
	else if (vars->size < 500)
		vars->n_group = 8;
	else
		vars->n_group = 14;
	group_sort(vars);
}
