/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:01:38 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 11:37:21 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_vars(t_vars *vars)
{
	vars->size = 0;
	vars->a = NULL;
	vars->b = NULL;
	vars->sorted = NULL;
	vars->n_piv = 0;
	vars->pivots = NULL;
}

int	main(int argc, char **argv)
{
	int	i;
	int	n;
	t_vars	vars;

	i = 1;
	init_vars(&vars);
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (check_atoi(n, argv[i]) == 0)
			return (ft_fprintf(2, "Error\n"), 1);
		lstadd_back(&vars.a, lst_new(n));
		if (lst_insert_sort(&vars.sorted, lst_new(n)) == 0)
			return (ft_printf("Dup\n"), 1);
		i++;
		vars.size++;
	}
	sort_stack(&vars);
	
	lst_clear(&vars.a);
	lst_clear(&vars.b);
	lst_clear(&vars.sorted);
}
