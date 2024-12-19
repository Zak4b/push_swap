/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:15:20 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 16:16:50 by asene            ###   ########.fr       */
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

	c[1] = (vars->size + 1) / 2;
	c[0] = c[1] - 1;
	while (lst_size(vars->a) > 0)
	{
		if (c[0] >= 0)
			num[0] = vars->sorted[c[0]];
		if (c[1] < vars->size)
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

void	group_sort(t_vars *vars)
{	
	int	i;
	int	group_id;
	int count[8] = {0};
	int exee;

	i = 0;
	vars->pivots = ft_calloc(vars->n_piv, sizeof(int));
	while (i < vars->n_piv)
	{
		exee = (vars->size - 1) * i / (vars->n_piv - 1);
		vars->pivots[i] = vars->sorted[(vars->size - 1) * i / (vars->n_piv - 1)];
		i++;
	}
	vars->pivots[vars->n_piv - 1]++;
	i = 0;
	group_id = 0;
	while (i < vars->size)
	{
		if (vars->sorted[i] >= vars->pivots[group_id] && vars->sorted[i] < vars->pivots[group_id + 1])
		{
			count[group_id]++;
		}
		else if (vars->sorted[i] == vars->pivots[group_id + 1])
		{
			group_id++;
			continue ;
		}
		i++;
	}
	
	int g1 = 3, g2 = 4;
	while (count[g1] > 0 || count[g2] > 0)
	{
		if (vars->a->n >= vars->pivots[g1] && vars->a->n < vars->pivots[g1 + 1])
		{
			push_to_b(vars);
			if (--count[g1] == 0 && g1 > 0)
				g1--;
		}
		if (vars->a->n >= vars->pivots[g2] && vars->a->n < vars->pivots[g2 + 1])
		{
			push_to_b(vars);
			rotate_b(vars);
			if (--count[g2] == 0 && g2 < 7)
				g2++;
		}
		rotate_a(vars);
	}
	
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
		return (messy_sort(vars));
	else if (vars->size < 500)
		vars->n_piv = 9;
	else
		vars->n_piv = 15;
	group_sort(vars);
}
