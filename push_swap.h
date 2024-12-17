/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:02:29 by asene             #+#    #+#             */
/*   Updated: 2024/12/17 14:44:00 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdlib.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int		n;
}	t_stack;


t_stack		*lst_new(int n);
void		lst_clear(t_stack **lst);
void		lstadd_front(t_stack **lst, t_stack *new);
void		lstadd_back(t_stack **lst, t_stack *new);
int			lst_insert_sort(t_stack **lst, t_stack *new);
t_stack	*lst_first(t_stack *lst);
t_stack	*lst_last(t_stack *lst);
