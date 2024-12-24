/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:16:49 by asene             #+#    #+#             */
/*   Updated: 2024/12/24 15:20:06 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(int argc, char **argv, t_vars *vars)
{
	int		i;
	int		n;
	t_stack	*sorted;
	t_stack	*e;

	sorted = NULL;
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (check_atoi(n, argv[i]) == 0)
			return (ft_fprintf(2, "Error\nValue \"%s\" is not a valid int\n",
					argv[i]), stack_clear(&sorted), clean_exit(vars, 1));
		stack_add_back(&vars->a, stack_new(n));
		e = stack_new(n);
		if (stack_insert_sort(&sorted, e) == 0)
			return (ft_fprintf(2, "Error\nDuplicate value \"%d\"\n",
					n), free(e), stack_clear(&sorted), clean_exit(vars, 1));
		i++;
		vars->size++;
	}
	vars->count_a = vars->size;
	vars->sorted = stack_to_array(sorted);
	stack_clear(&sorted);
}

int	*stack_to_array(t_stack *s)
{
	int	i;
	int	size;
	int	*array;

	size = stack_size(s);
	array = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		array[i] = s->n;
		s = s->next;
		i++;
	}
	return (array);
}
