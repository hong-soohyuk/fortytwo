/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:26 by soohong           #+#    #+#             */
/*   Updated: 2023/01/10 18:04:07 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	print_queue(t_dequeue *a, t_dequeue *b)
{
	if (!a || !b)
		return ;
	t_node	*current_a;
	t_node	*current_b;

	int max = a->size > b->size ? a->size : b->size;
	int	i = -1;
	current_a = a->head;
	current_b = b->head;
	printf("|	A	|	B	|\n");
	while (++i < max)
	{
		if (current_a && current_b)
		{
			printf("|	%d	|	%d	|\n", current_a->value, current_b->value);
			current_a = current_a->next;
			current_b = current_b->next;
		}
		else if (current_a == NULL)
		{
			printf("|		|	%d	|\n", current_b->value);
			current_b = current_b->next;
		}
		else if (current_b == NULL)
		{
			printf("|	%d	|		|\n", current_a->value);
			current_a = current_a->next;
		}
		else if (current_a == NULL && current_b == NULL)
		{
			printf("|	end	|	end	|\n");
			break ;
		}
	}
	printf("|	end	|	end	|\n");
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
	// QA
	sa(a, cmds);
	pb(a, b, cmds);
	pa(a, b, cmds);
	pa(a, b, cmds);
	pa(a, b, cmds);
	pb(a, b, cmds);
	pb(a, b, cmds);
	pb(a, b, cmds);
	rra(a, cmds);
	rra(a, cmds);
	sb(a, cmds);
	ra(a, cmds);
	rb(b, cmds);
	rrb(b, cmds);
	//
	print_queue(a, b);
	stdout_cmds(cmds);
	exit_safe(a, b, EXIT_SUCCESS);
}
