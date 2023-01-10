/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:26 by soohong           #+#    #+#             */
/*   Updated: 2023/01/10 22:55:04 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_queue(t_dequeue *a, t_dequeue *b)
{
	t_node	*current_a;
	t_node	*current_b;

	if (!a || !b)
		return ;
	int max = a->size > b->size ? a->size : b->size;
	int	i = -1;
	current_a = a->head;
	current_b = b->head;
	printf("|	A		|	B		|\n");
	while (++i < max)
	{
		if (current_a && current_b)
		{
			printf("|	%d		|	%d		|\n", current_a->value, current_b->value);
			current_a = current_a->next;
			current_b = current_b->next;
		}
		else if (current_a == NULL)
		{
			printf("|			|	%d		|\n", current_b->value);
			current_b = current_b->next;
		}
		else if (current_b == NULL)
		{
			printf("|	%d		|			|\n", current_a->value);
			current_a = current_a->next;
		}
		else if (current_a == NULL && current_b == NULL)
		{
			printf("|	end		|	end		|\n");
			break ;
		}
	}
	printf("|	end		|	end		|\n");
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
	quick_sort(a, b, cmds);
	print_queue(a, b);
	stdout_cmds(cmds);
	exit_safe(a, b, EXIT_SUCCESS);
}
