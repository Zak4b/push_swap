/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:37:06 by asene             #+#    #+#             */
/*   Updated: 2024/12/19 11:37:26 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_atoi(int n, char *s)
{
	char	*temp;
	int		res;

	temp = ft_itoa(n);
	res = ft_strncmp(s, temp, 15);
	free(temp);
	return (res == 0);
}