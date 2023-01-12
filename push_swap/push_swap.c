/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:47:16 by soohong           #+#    #+#             */
/*   Updated: 2023/01/12 23:07:55 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stdout_queue(t_dequeue *a, t_dequeue *b)
{
	t_node	*current_a;
	t_node	*current_b;

	if (!a || !b)
		return ;
	current_a = a->head;
	current_b = b->head;
	printf("|	A			|	B			|\n");
	while (current_a && current_b)
	{
		printf("|	%d			|	%d			|\n",
				current_a->value, current_b->value);
			current_a = current_a->next;
			current_b = current_b->next;
	}
	while (current_a || current_b)
	{
		if (current_a == NULL)
		{
			printf("|				|	%d			|\n", current_b->value);
			current_b = current_b->next;
		}
		else if (current_b == NULL)
		{
			printf("|	%d			|				|\n", current_a->value);
			current_a = current_a->next;
		}
		else if (current_a == NULL && current_b == NULL)
		{
			printf("|	end			|	end			|\n");
			break ;
		}
	}
	printf("|	end			|	end			|\n");
}

int	main(int argc, char **argv)
{
	t_dequeue	*a;
	t_dequeue	*b;
	t_cmds		*cmds;

	if (argc == 1)
		exit_safe(NULL, NULL, EXIT_FAILURE);
	a = (t_dequeue *)malloc(sizeof(t_dequeue));
	b = (t_dequeue *)malloc(sizeof(t_dequeue));
	cmds = (t_cmds *)malloc(sizeof(t_cmds));
	init_dequeue(a, b, argv, argc);
	if (argc == 4)
		hardsort(a, cmds);
	else
	{
		partition(a, b, cmds);
		greedy_sort(a, b, cmds);
	}
	stdout_cmds(cmds);
	exit_safe(a, b, EXIT_SUCCESS);
}
