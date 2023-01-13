/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:47:16 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 15:45:28 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	is_sorted(t_dequeue *a)
{
	t_node	*curr;

	if (a->size == 1)
		return (1);
	curr = a->head;
	while (curr)
	{
		if (curr->next != NULL && curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_dequeue	*a;
	t_dequeue	*b;
	t_cmds		*cmds;

	if (argc == 1)
		exit_safe(NULL, NULL, EXIT_SUCCESS);
	a = (t_dequeue *)malloc(sizeof(t_dequeue));
	b = (t_dequeue *)malloc(sizeof(t_dequeue));
	cmds = (t_cmds *)malloc(sizeof(t_cmds));
	init_dequeue(a, b, argv, argc);
	if (is_sorted(a))
		exit_safe(a, b, EXIT_SUCCESS);
	else
	{
		partition(a, b, cmds);
		greedy_sort(a, b, cmds);
	}
	stdout_cmds(cmds);
	exit_safe(a, b, EXIT_SUCCESS);
}
