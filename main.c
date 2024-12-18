/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:01:38 by asene             #+#    #+#             */
/*   Updated: 2024/12/18 14:55:11 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	while (s)
	{
		ft_printf("%d -> ", s->n);
		s = s->next;
	}
	ft_putstr_fd("NULL\n", 1);
}

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
	t_vars	vars;
	t_stack *dup = NULL;

	i = 1;
	vars.a = NULL;
	vars.b = NULL;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (check_atoi(n, argv[i]) == 0)
			return (ft_fprintf(2, "Error\n"), 1);
		lstadd_back(&vars.a, lst_new(n));
		if (lst_insert_sort(&dup, lst_new(n)) == 0)
			return (ft_printf("Dup\n"), 1);
		i++;
	}
	
	lst_clear(&vars.a);
	lst_clear(&vars.b);
	lst_clear(&dup);
}
