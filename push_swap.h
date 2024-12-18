/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:02:29 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 22:03:19 by asene            ###   ########.fr       */
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
	int		n;
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
}	t_vars;

int			check_atoi(int n, char *s);

t_stack		*lst_new(int n);
void		lst_clear(t_stack **lst);
void		lstadd_front(t_stack **lst, t_stack *new);
void		lstadd_back(t_stack **lst, t_stack *new);
int			lst_insert_sort(t_stack **lst, t_stack *new);
t_stack		*lst_first(t_stack *lst);
t_stack		*lst_last(t_stack *lst);
int			lst_size(t_stack *s);
int			is_sorted(t_stack *s);

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


void		print_stack(t_stack *s);

void		sort_stack(t_vars *vars);
void		group_sort(t_vars *vars);

int			find_pos(t_stack *s, int value);
int			get_sorted_pos(t_vars *vars, int value);
#endif