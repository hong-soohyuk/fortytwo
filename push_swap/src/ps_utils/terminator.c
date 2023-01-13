/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:35 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 15:45:28 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	free_deq(t_dequeue *q)
{
	t_node	*next;
	t_node	*current;

	current = q->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(q);
}

void	exit_safe(t_dequeue *a, t_dequeue *b, int exit_code)
{
	if (a)
		free_deq(a);
	if (b)
		free_deq(b);
	if (exit_code)
		write(2, &"Error\n", 6);
	exit(exit_code);
}
