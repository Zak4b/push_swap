/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:20:55 by asene             #+#    #+#             */
/*   Updated: 2024/12/17 15:22:36 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i, n;
	t_stack *a = NULL;
	t_stack *b = NULL;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (check_atoi(n, argv[i]) == 0)
			return (ft_fprintf(2, "Error\n"), 1);
		lstadd_back(&a, lst_new(n));
		if (lst_insert_sort(&dup, lst_new(n)) == 0)
			return (ft_printf("Dup\n"), 1);
		i++;
	}
}