/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:55:09 by asene             #+#    #+#             */
/*   Updated: 2024/12/21 14:53:26 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_bounds(t_vars *vars);
int		is_in_group(t_vars *vars, int value, int group);
void	count_elem_groups(t_vars *vars, int count[32]);
t_stack	*find_min_group(t_vars *vars, t_stack *s, int group);
t_stack	*find_max_group(t_vars *vars, t_stack *s, int group);