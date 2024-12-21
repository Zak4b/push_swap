/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:37:06 by asene             #+#    #+#             */
/*   Updated: 2024/12/21 16:33:38 by asene            ###   ########.fr       */
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
	int	temp;

	if (rot_1 > rot_2)
	{
		temp = rot_1;
		rot_1 = rot_2;
		rot_2 = temp;
	}
	if (rot_2 > vars->count_a / 2)
	{
		rot_2 = vars->count_a - rot_2;
		while (rot_2-- > 0)
			rev_rotate_a(vars);
	}
	else
		while (rot_1-- > 0)
			rotate_a(vars);
}

void	smart_rotate_b(t_vars *vars, int rot_1, int rot_2)
{
	int	temp;

	if (rot_1 > rot_2)
	{
		temp = rot_1;
		rot_1 = rot_2;
		rot_2 = temp;
	}
	if (rot_2 > vars->count_b / 2)
	{
		rot_2 = vars->count_b - rot_2;
		while (rot_2-- > 0)
			rev_rotate_b(vars);
	}
	else
		while (rot_1-- > 0)
			rotate_b(vars);
}
