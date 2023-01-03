/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:34 by soohong           #+#    #+#             */
/*   Updated: 2023/01/03 18:58:20 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int size, char **argv, t_stack *a, t_stack *b)
{
	a = (t_stack *)malloc(sizeof(t_stack));
	a->list = (int *)malloc(sizeof(int) * (size - 1));
	b = (t_stack *)malloc(sizeof(t_stack));
	b->list = (int *)malloc(sizeof(int) * (size - 1));
}

int	validate_input(char *argv)
{
	
}
