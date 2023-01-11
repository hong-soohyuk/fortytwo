/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_swaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:27 by soohong           #+#    #+#             */
/*   Updated: 2023/01/11 19:33:50 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_dequeue *queue)
{
	t_node	*curr_head;
	t_node	*next_head;

	curr_head = queue->head;
	next_head = queue->head->next;
	curr_head->prev = next_head;
	curr_head->next = next_head->next;
	next_head->prev = NULL;
	next_head->next = curr_head;
	queue->head = next_head;
}

void	sa(t_dequeue *a, t_cmds *cmds)
{
	if (a->size < 2)
		return ;
	swap(a);
	cmd_node(cmds, CMD_SA);
}

void	sb(t_dequeue *b, t_cmds *cmds)
{
	if (b->size < 2)
		return ;
	swap(b);
	cmd_node(cmds, CMD_SB);
}

void	ss(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	swap(a);
	swap(b);
	cmd_node(cmds, CMD_SS);
}
