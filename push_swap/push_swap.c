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

void	print_queue(t_dequeue *a)
{
	if (!a)
		return ;
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
	t_dequeue	*a;
	t_dequeue	*b;
	
	a = (t_dequeue *)malloc(sizeof(t_dequeue));
	b = (t_dequeue *)malloc(sizeof(t_dequeue));
	if (argc == 1)
		exit_safe(a, b, EXIT_FAILURE);
	init_dequeue(a, argv, argc);
	print_queue(a);
	exit_safe(a, b, EXIT_SUCCESS);
}
