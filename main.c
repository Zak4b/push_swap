/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:01:38 by asene             #+#    #+#             */
/*   Updated: 2024/12/17 15:22:15 by asene            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	i;
	int	n;
	t_stack *a = NULL;
	t_stack *b = NULL;
	t_stack *dup = NULL;

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
	lst_clear(&a);
	lst_clear(&b);
	lst_clear(&dup);
}
