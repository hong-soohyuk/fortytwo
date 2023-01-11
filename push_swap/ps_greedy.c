/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:39:08 by soohong           #+#    #+#             */
/*   Updated: 2023/01/11 19:46:38 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	get_best_a(t_dequeue *a, int btoa)
{
	t_node	*curr;
	int		rot_a;

	curr = a->head;
	rot_a = 0;
	while (curr)
	{
		if (curr->value > btoa && a->tail->value < btoa)
			break ;
		if (a->size > 0 && curr->prev != NULL && curr->prev->value > btoa
			&& curr->value > btoa && curr->prev->value > curr->value)
			break ;
		if (a->size > 0 && curr->prev != NULL && curr->prev->value < btoa
			&& curr->value > btoa && curr->prev->value < curr->value)
			break ;
		if (a->size > 0 && curr->prev != NULL && curr->prev->value < btoa
			&& curr->value < btoa && curr->prev->value > curr->value)
			break ;
		curr = curr->next;
		rot_a++;
	}
	if (rot_a > a->size / 2)
		return (rot_a - a->size);
	return (rot_a);
}

static void	set_bests(t_dequeue *a, t_dequeue *b, int *best_a, int *best_b)
{
	t_node	*curr_b;
	int		best;
	int		rot_a;
	int		rot_b;

	curr_b = b->head;
	best = 2147483647;
	rot_b = 0;
	while (curr_b)
	{
		rot_a = get_best_a(a, curr_b->value);
		if (absolute(rot_a) + rot_b < best)
		{
			best = absolute(rot_a) + rot_b;
			*best_a = rot_a;
			*best_b = rot_b;
		}
		curr_b = curr_b->next;
		rot_b++;
	}
}

void	greedy_sort(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	int	bests[2];

	bests[0] = 0;
	bests[1] = 0;
	while (b->size != 0)
	{
		set_bests(a, b, &bests[0], &bests[1]);
		rotate_deqs(a, b, cmds, bests);
	}
}