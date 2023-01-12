/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_swaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:27 by soohong           #+#    #+#             */
/*   Updated: 2023/01/12 18:52:02 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_dequeue *queue)
{
	int temp;
	
	temp = queue->head->value;
	queue->head->value = queue->head->next->value;
	queue->head->next->value = temp;
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
