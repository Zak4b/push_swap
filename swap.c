/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:41:05 by asene             #+#    #+#             */
/*   Updated: 2024/12/24 10:35:33 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int	temp;

	temp = s->n;
	s->n = s->next->n;
	s->next->n = temp;
}

void	swap_a(t_vars *vars)
{
	swap(vars->a);
	if (vars->display_instructions)
		ft_putendl_fd("sa", 1);
}

void	swap_b(t_vars *vars)
{
	swap(vars->b);
	if (vars->display_instructions)
		ft_putendl_fd("sb", 1);
}

void	swap_both(t_vars *vars)
{
	swap(vars->a);
	swap(vars->b);
	if (vars->display_instructions)
		ft_putendl_fd("ss", 1);
}
