/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:54:47 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 22:06:35 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

int	is_in_group(t_vars *vars, int value, int group)
{
	return (value >= vars->bounds[group] && value < vars->bounds[group + 1]);
}

void	count_elem_groups(t_vars *vars, int count[32])
{
	int			i;
	int			group_id;

	i = 0;
	group_id = 0;
	while (i < vars->size)
	{
		if (vars->sorted[i] >= vars->bounds[group_id]
			&& vars->sorted[i] < vars->bounds[group_id + 1])
			count[group_id]++;
		else if (vars->sorted[i] == vars->bounds[group_id + 1])
		{
			group_id++;
			continue ;
		}
		i++;
	}
}

t_stack	*find_min_group(t_vars *vars, t_stack *s, int group)
{
	t_stack	*res;

	res = NULL;
	while (s)
	{
		if (is_in_group(vars, s->n, group))
		{
			if (!res || s->n < res->n)
				res = s;
		}
		s = s->next;
	}
	return (res);
}

t_stack	*find_max_group(t_vars *vars, t_stack *s, int group)
{
	t_stack	*res;

	res = NULL;
	while (s)
	{
		if (is_in_group(vars, s->n, group))
		{
			if (!res || s->n > res->n)
				res = s;
		}
		s = s->next;
	}
	return (res);
}
