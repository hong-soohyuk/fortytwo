/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:27 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 15:45:28 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static void	swap(t_dequeue *queue)
{
	int	temp;

	temp = queue->head->value;
	queue->head->value = queue->head->next->value;
	queue->head->next->value = temp;
}

void	sa(t_dequeue *a)
{
	if (a->size < 2)
		return ;
	swap(a);
}

void	sb(t_dequeue *b)
{
	if (b->size < 2)
		return ;
	swap(b);
}

void	ss(t_dequeue *a, t_dequeue *b)
{
	swap(a);
	swap(b);
}
