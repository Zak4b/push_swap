/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:01:38 by asene             #+#    #+#             */
/*   Updated: 2024/12/20 12:00:19 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*stack_to_array(t_stack *s)
{
	int	i;
	int	size;
	int	*array;

	size = lst_size(s);
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

void	clean_exit(t_vars *vars, int exit_code)
{
	lst_clear(&vars->a);
	lst_clear(&vars->b);
	free(vars->sorted);
	exit(exit_code);
}

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
					argv[i]), lst_clear(&sorted), clean_exit(vars, 1));
		lstadd_back(&vars->a, lst_new(n));
		e = lst_new(n);
		if (lst_insert_sort(&sorted, e) == 0)
			return (ft_fprintf(2, "Error\nDuplicate value \"%d\"\n",
					n), free(e), lst_clear(&sorted), clean_exit(vars, 1));
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
	sort_stack(&vars);
	clean_exit(&vars, EXIT_SUCCESS);
}
