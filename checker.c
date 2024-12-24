/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:01:38 by asene             #+#    #+#             */
/*   Updated: 2024/12/24 15:27:50 by asene            ###   ########.fr       */
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
	vars->display_instructions = 0;
}

void	exec_rotate(t_vars *vars, t_list *inst)
{
	if (ft_strncmp((char *)inst->content, "ra\n", 3) == 0)
		rotate_a(vars);
	else if (ft_strncmp((char *)inst->content, "rb\n", 3) == 0)
		rotate_b(vars);
	else if (ft_strncmp((char *)inst->content, "rr\n", 3) == 0)
		rotate_both(vars);
	else if (ft_strncmp((char *)inst->content, "rra\n", 4) == 0)
		rev_rotate_a(vars);
	else if (ft_strncmp((char *)inst->content, "rrb\n", 4) == 0)
		rev_rotate_b(vars);
	else if (ft_strncmp((char *)inst->content, "rrr\n", 4) == 0)
		rev_rotate_both(vars);
}

void	exec(t_vars *vars, t_list *inst)
{
	while (inst)
	{
		if (((char *)inst->content)[0] == 'r')
			exec_rotate(vars, inst);
		else if (ft_strncmp((char *)inst->content, "sa\n", 3) == 0)
			swap_a(vars);
		else if (ft_strncmp((char *)inst->content, "sb\n", 3) == 0)
			swap_b(vars);
		else if (ft_strncmp((char *)inst->content, "ss\n", 3) == 0)
			swap_both(vars);
		else if (ft_strncmp((char *)inst->content, "pa\n", 3) == 0)
			push_to_a(vars);
		else if (ft_strncmp((char *)inst->content, "pb\n", 3) == 0)
			push_to_b(vars);
		inst = inst->next;
	}
}

void	read_instruction(t_list **lst)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_lstadd_back(lst, ft_lstnew(line));
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_list	*instructions;

	if (argc < 2)
		return (0);
	init_vars(&vars);
	fill_stack(argc, argv, &vars);
	instructions = NULL;
	read_instruction(&instructions);
	if (instructions)
		exec(&vars, instructions);
	if (is_sorted(vars.a) && stack_size(vars.b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (ft_lstclear(&instructions, free), clean_exit(&vars, 0), 0);
}
