/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:41:05 by asene             #+#    #+#             */
/*   Updated: 2024/12/20 10:50:12 by asene            ###   ########.fr       */
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
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_vars *vars)
{
	swap(vars->b);
	ft_putendl_fd("sb", 1);
}

void	swap_both(t_vars *vars)
{
	swap(vars->a);
	swap(vars->b);
	ft_putendl_fd("ss", 1);
}
