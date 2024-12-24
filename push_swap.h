/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:02:29 by asene             #+#    #+#             */
/*   Updated: 2024/12/24 15:21:06 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stdlib.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				n;
}	t_stack;

typedef struct s_vars
{
	int		size;
	t_stack	*a;
	int		count_a;
	t_stack	*b;
	int		count_b;
	int		*sorted;
	int		n_group;
	int		*bounds;
	int		display_instructions;
}	t_vars;

t_stack		*stack_new(int n);
void		stack_clear(t_stack **stack);
void		stack_add_front(t_stack **stack, t_stack *new);
void		stack_add_back(t_stack **stack, t_stack *new);
int			stack_insert_sort(t_stack **stack, t_stack *new);
t_stack		*stack_first(t_stack *stack);
t_stack		*stack_last(t_stack *stack);
int			stack_size(t_stack *s);
int			is_sorted(t_stack *s);
void		print_stack(t_stack *s);

void		push_to_a(t_vars *vars);
void		push_to_b(t_vars *vars);
void		rotate_a(t_vars *vars);
void		rotate_b(t_vars *vars);
void		rotate_both(t_vars *vars);
void		rev_rotate_a(t_vars *vars);
void		rev_rotate_b(t_vars *vars);
void		rev_rotate_both(t_vars *vars);
void		swap_a(t_vars *vars);
void		swap_b(t_vars *vars);
void		swap_both(t_vars *vars);

void		sort_stack(t_vars *vars);
void		group_sort(t_vars *vars);

int			check_atoi(int n, char *s);
int			find_pos(t_stack *s, int value);
int			get_sorted_pos(t_vars *vars, int value);
void		clean_exit(t_vars *vars, int exit_code);
void		fill_stack(int argc, char **argv, t_vars *vars);
int			*stack_to_array(t_stack *s);

void		smart_rotate_a(t_vars *vars, int rot_1, int rot_2);
void		smart_rotate_b(t_vars *vars, int rot_1, int rot_2);
#endif