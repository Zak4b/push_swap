/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:01:38 by asene             #+#    #+#             */
/*   Updated: 2024/12/24 11:16:27 by asene            ###   ########.fr       */
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
	vars->display_instructions = 1;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_vars(&vars);
	fill_stack(argc, argv, &vars);
	sort_stack(&vars);
	clean_exit(&vars, EXIT_SUCCESS);
}
