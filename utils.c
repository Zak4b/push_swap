/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:37:06 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 22:03:05 by asene            ###   ########.fr       */
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