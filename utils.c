/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:37:06 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 13:21:32 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_atoi(int n, char *s)
{
	char	*temp;
	int		res;

	temp = ft_itoa(n);
	res = ft_strncmp(s, temp, 15);
	free(temp);
	return (res == 0);
}

int	get_sorted_pos(t_vars *vars, int value)
{
	int	i;

	i = 0;
	while (i < vars->size)
	{
		if (vars->sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_pos(t_stack *s, int value)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s->n == value)
			return (i);
		i++;
		s = s->next;
	}
	return (-1);
}

void	smart_rotate_a(t_vars *vars, int rot_1, int rot_2)
{
	void	(*f_min)(t_vars *);
	void	(*f_max)(t_vars *);

	if (vars->count_a - rot_1 < rot_1)
	{
		f_min = rev_rotate_a;
		rot_1 = vars->count_a - rot_1;
	}
	else
		f_min = rotate_a;
	if (vars->count_a - rot_2 < rot_2)
	{
		f_max = rev_rotate_a;
		rot_2 = vars->count_a - rot_2;
	}
	else
		f_max = rotate_a;
	if (rot_2 < rot_1)
		while (rot_2-- > 0)
			f_max(vars);
	else
		while (rot_1-- > 0)
			f_min(vars);
}

void	smart_rotate_b(t_vars *vars, int min_pos, int max_pos)
{
	void	(*f_min)(t_vars *);
	void	(*f_max)(t_vars *);

	if (vars->count_b - min_pos < min_pos)
	{
		f_min = rev_rotate_b;
		min_pos = vars->count_b - min_pos;
	}
	else
		f_min = rotate_b;
	if (vars->count_b - max_pos < max_pos)
	{
		f_max = rev_rotate_b;
		max_pos = vars->count_b - max_pos;
	}
	else
		f_max = rotate_b;
	if (max_pos < min_pos + 2)
		while (max_pos-- > 0)
			f_max(vars);
	else
		while (min_pos-- > 0)
			f_min(vars);
}
