/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_pushes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:15:45 by soohong           #+#    #+#             */
/*   Updated: 2023/01/10 18:23:19 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*pop(t_dequeue *src)
{
	t_node	*popped;

	popped = src->head;
	if (src->size == 1)
	{
		src->head = NULL;
		src->tail = NULL;
	}
	else
	{
		src->head = src->head->next;
		src->head->prev = NULL;
	}
	src->size--;
	return (popped);
}

static void	push(t_dequeue *dest, t_node *popped)
{
	if (dest->size == 0)
	{
		popped->next = NULL;
		dest->head = popped;
		dest->tail = popped;
	}
	else
	{
		popped->next = dest->head;
		dest->head->prev = popped;
		dest->head = popped;
	}
	dest->size++;
}

void	pa(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	if (b->size == 0)
		return ;
	push(a, pop(b));
	cmd_node(cmds, CMD_PA);
}

void	pb(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	if (a->size == 0)
		return ;
	push(b, pop(a));
	cmd_node(cmds, CMD_PB);
}
