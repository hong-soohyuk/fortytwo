/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:26 by soohong           #+#    #+#             */
/*   Updated: 2023/01/10 15:42:36 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_queue(t_dequeue *queue)
{
	if (!queue)
		return ;
	t_node	*current;

	current = queue->head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
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
	init_dequeue(a, argv, argc);
	// sa(a, cmds);
	pb(b, a, cmds);
	pb(b, a, cmds);
	pb(b, a, cmds);
	printf("A\n");
	print_queue(a);
	printf("B\n");
	print_queue(b);
	stdout_cmds(cmds);
	exit_safe(a, b, EXIT_SUCCESS);
}
