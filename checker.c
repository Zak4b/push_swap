/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:01:38 by asene             #+#    #+#             */
/*   Updated: 2024/12/20 11:36:50 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	init_vars(t_vars *vars)
{
	vars->size = 0;
	vars->a = NULL;
	vars->count_a = 0;
	vars->b = NULL;
	vars->count_b = 0;
	vars->sorted = NULL;
	vars->n_group = 0;
	vars->bounds = NULL;
}

void	fill_stack(int argc, char **argv, t_vars *vars)
{
	int		i;
	int		n;
	t_stack	*sorted;

	sorted = NULL;
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (check_atoi(n, argv[i]) == 0)
		{
			ft_printf("%d %s", n, argv[i]);
		}
		lstadd_back(&vars->a, lst_new(n));
		if (lst_insert_sort(&sorted, lst_new(n)) == 0)
		{
			
		}
		i++;
		vars->size++;
	}
	vars->count_a = vars->size;
	vars->sorted = stack_to_array(sorted);
	lst_clear(&sorted);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_vars(&vars);
	fill_stack(argc, argv, &vars);

	lst_clear(&vars.a);
	lst_clear(&vars.b);
	free(vars.sorted);
}
*/