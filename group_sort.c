/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:55:27 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 13:23:05 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "groups.h"

void	rotate_to_next(t_vars *vars, int group_1, int group_2)
{
	t_stack	*s1;
	t_stack	*s2;
	int		p1;
	int		p2;

	s1 = vars->a;
	p1 = 0;
	while (s1 && !is_in_group(vars, s1->n, group_1)
		&& !is_in_group(vars, s1->n, group_2))
	{
		s1 = s1->next;
		p1++;
	}
	if (!s1)
		return ;
	s2 = stack_last(s1);
	p2 = vars->count_a - 1;
	while (s2 && !is_in_group(vars, s2->n, group_1)
		&& !is_in_group(vars, s2->n, group_2))
	{
		s2 = s2->prev;
		p2--;
	}
	if (s2)
		smart_rotate_a(vars, p1, p2);
}

void	push_by_group(t_vars *vars)
{
	int			g1;
	int			g2;
	static int	count[32] = {0};

	count_elem_groups(vars, count);
	g2 = (vars->n_group + 1) / 2;
	g1 = g2 - 1;
	while (count[g1] > 0 || count[g2] > 0)
	{
		if (vars->a && is_in_group(vars, vars->a->n, g1))
		{
			push_to_b(vars);
			rotate_b(vars);
			if (--count[g1] == 0 && g1 > 0)
				g1--;
		}
		else if (vars->a && is_in_group(vars, vars->a->n, g2))
		{
			push_to_b(vars);
			if (--count[g2] == 0 && g2 < vars->n_group - 1)
				g2++;
		}
		else
			rotate_a(vars);
	}
}

void	pull_group(t_vars *vars, int group_id)
{
	t_stack	*min;
	t_stack	*max;
	int		min_pos;
	int		max_pos;

	while (1)
	{
		min = find_min_group(vars, vars->b, group_id);
		max = find_max_group(vars, vars->b, group_id);
		if (!min || !max)
			break ;
		min_pos = find_pos(vars->b, min->n);
		max_pos = find_pos(vars->b, max->n);
		if (min_pos == -1 || max_pos == -1)
			break ;
		smart_rotate_b(vars, min_pos, max_pos);
		push_to_a(vars);
		if (vars->a->n == min->n)
			rotate_a(vars);
	}
}

void	group_sort(t_vars *vars)
{
	int	group_id;

	set_bounds(vars);
	push_by_group(vars);
	group_id = vars->n_group - 1;
	while (group_id >= 0)
	{
		pull_group(vars, group_id--);
		while (!is_sorted(vars->a))
			rev_rotate_a(vars);
	}
	free(vars->bounds);
}
