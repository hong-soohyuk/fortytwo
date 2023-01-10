/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_reverses.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:22 by soohong           #+#    #+#             */
/*   Updated: 2023/01/10 22:47:23 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_dequeue *deq)
{
	t_node	*new_head;

	if (deq->size == 0)
		return ;
	new_head = deq->tail;
	deq->tail = deq->tail->prev;
	deq->tail->next = NULL;
	new_head->prev = NULL;
	new_head->next = deq->head;
	deq->head->prev = new_head;
	deq->head = new_head;
}

void	rra(t_dequeue *a, t_cmds *cmds)
{
	reverse(a);
	cmd_node(cmds, CMD_RRA);
}

void	rrb(t_dequeue *b, t_cmds *cmds)
{
	reverse(b);
	cmd_node(cmds, CMD_RRB);
}

void	rrr(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	reverse(a);
	reverse(b);
	cmd_node(cmds, CMD_RRR);
}
