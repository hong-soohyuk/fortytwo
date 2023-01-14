/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:22 by soohong           #+#    #+#             */
/*   Updated: 2023/01/14 18:30:49 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static void	reverse(t_dequeue *deq)
{
	t_node	*new_head;

	if (deq->size == 0 || deq->size == 1)
		return ;
	new_head = deq->tail;
	deq->tail = deq->tail->prev;
	deq->tail->next = NULL;
	new_head->prev = NULL;
	new_head->next = deq->head;
	deq->head->prev = new_head;
	deq->head = new_head;
}

void	rra(t_dequeue *a)
{
	if (a->size == 0 || a->size == 1)
		return ;
	reverse(a);
}

void	rrb(t_dequeue *b)
{
	if (b->size == 0 || b->size == 1)
		return ;
	reverse(b);
}

void	rrr(t_dequeue *a, t_dequeue *b)
{
	if (a->size != 0 && a->size != 1 && b->size != 0 && b->size != 1)
	{
		reverse(a);
		reverse(b);
	}
}
