/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:39 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 15:45:28 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
	popped->prev = NULL;
	popped->next = NULL;
	(src->size)--;
	return (popped);
}

static void	push(t_dequeue *dest, t_node *pushed)
{
	if (dest->size == 0)
	{
		dest->head = pushed;
		dest->tail = pushed;
	}
	else
	{
		pushed->next = dest->head;
		dest->head->prev = pushed;
		dest->head = pushed;
	}
	(dest->size)++;
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
