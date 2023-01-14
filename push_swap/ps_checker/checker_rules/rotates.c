/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:24 by soohong           #+#    #+#             */
/*   Updated: 2023/01/14 18:29:58 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static void	rotate(t_dequeue *deq)
{
	t_node	*new_tail;

	if (deq->size == 0 || deq->size == 1)
		return ;
	new_tail = deq->head;
	deq->head = deq->head->next;
	deq->head->prev = NULL;
	deq->tail->next = new_tail;
	new_tail->next = NULL;
	new_tail->prev = deq->tail;
	deq->tail = new_tail;
}

void	ra(t_dequeue *a)
{
	if (a->size == 0 || a->size == 1)
		return ;
	rotate(a);
}

void	rb(t_dequeue *b)
{
	if (b->size == 0 || b->size == 1)
		return ;
	rotate(b);
}

void	rr(t_dequeue *a, t_dequeue *b)
{
	if (a->size != 0 && a->size != 1 && b->size != 0 && b->size != 1)
	{
		rotate(a);
		rotate(b);
	}
}
