/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:24 by soohong           #+#    #+#             */
/*   Updated: 2023/01/11 19:33:51 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	rotate(t_dequeue *deq)
{
	t_node	*new_tail;

	new_tail = deq->head;
	deq->head = deq->head->next;
	deq->head->prev = NULL;
	deq->tail->next = new_tail;
	new_tail->next = NULL;
	new_tail->prev = deq->tail;
	deq->tail = new_tail;
}

void	ra(t_dequeue *a, t_cmds *cmds)
{
	if (a->size == 0 || a->size == 1)
		return ;
	rotate(a);
	cmd_node(cmds, CMD_RA);
}

void	rb(t_dequeue *b, t_cmds *cmds)
{
	if (b->size == 0 || b->size == 1)
		return ;
	rotate(b);
	cmd_node(cmds, CMD_RB);
}

void	rr(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	rotate(a);
	rotate(b);
	cmd_node(cmds, CMD_RR);
}
