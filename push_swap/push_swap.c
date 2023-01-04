/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:26 by soohong           #+#    #+#             */
/*   Updated: 2023/01/03 18:54:52 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	print_queue(t_stack *a)
{
	t_node	*current;

	current = a->head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	// t_stack	*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	// b = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 1)
		return (error_terminate());
	init_stacks(a, argv, argc);
	print_queue(a);
	// free(a);
	// free(b);
	return (0);
}
