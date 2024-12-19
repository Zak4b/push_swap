/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:55:27 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 23:04:27 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "groups.h"

void	set_bounds(t_vars *vars)
{
	int	i;

	i = 0;
	vars->bounds = ft_calloc(vars->n_group + 1, sizeof(int));
	while (i <= vars->n_group)
	{
		vars->bounds[i] = vars->sorted[(vars->size - 1) * i / vars->n_group];
		i++;
	}
	vars->bounds[vars->n_group]++;
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

void	smart_rotate(t_vars *vars, t_stack *s, int rot_1, int rot_2)
{
	int	temp;
	int	stack_size;

	stack_size = lst_size(s);
	if (rot_1 > rot_2)
	{
		temp = rot_1;
		rot_1 = rot_2;
		rot_2 = temp;
	}
	if (rot_2 > stack_size / 2)
	{
		rot_2 = stack_size - rot_2;
		while (rot_2-- > 0)
			rev_rotate_b(vars);
	}
	else
		while (rot_1-- > 0)
			rotate_b(vars);
}

void	pull_group(t_vars *vars, int group_id)
{
	t_stack	*min;
	t_stack	*max;
	int	min_pos;
	int	max_pos;

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
		smart_rotate(vars, vars->b, min_pos, max_pos);
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
}
