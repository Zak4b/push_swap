/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:15:20 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 14:25:37 by asene            ###   ########.fr       */
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
		if (current == vars->sorted[0] || ((vars->size == 5) && current == vars->sorted[1]))
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

void	messy_sort(t_vars *vars)
{
	int	c[2];
	int	num[2];

	c[0] = vars->size / 2;
	c[1] = (vars->size + 1) / 2;
	while (lst_size(vars->a) > 0)
	{
		num[0] = vars->sorted[c[0]];
		num[1] = vars->sorted[c[1]];
		if (vars->a->n == num[1])
		{
			push_to_b(vars);
			c[1]++;
		}
		else if (vars->a->n == num[0])
		{
			push_to_b(vars);
			rotate_b(vars);
			c[0]--;
		}
		rotate_a(vars);
	}
	while (vars->b != NULL)
		push_to_a(vars);
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
	else if (vars->size <= 5)
		return (sort_4_to_5(vars));
	else if (vars->size <= 99)
		messy_sort(vars);
	vars->n_piv = 14;
	vars->pivots = ft_calloc(vars->n_piv, sizeof(int));
	i = 0;
	while (i < vars->n_piv)
	{
		vars->pivots[i] = vars->sorted[vars->size * i / vars->n_piv];
		i++;
	}
	i = 0;
}
