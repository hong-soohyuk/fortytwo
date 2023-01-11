/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:39:08 by soohong           #+#    #+#             */
/*   Updated: 2023/01/11 23:47:37 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			&& curr->value > btoa && curr->prev->value > curr->value) // 2 3 / 1
			break ;
		if (a->size > 0 && curr->prev != NULL && curr->prev->value < btoa
			&& curr->value > btoa && curr->prev->value < curr->value) // 1 3 / 2
			break ;
		if (a->size > 0 && curr->prev != NULL && curr->prev->value < btoa
			&& curr->value < btoa && curr->prev->value > curr->value) // 3 2 / 1
			break ;
		curr = curr->next;
		rot_a++;
	}
	if (rot_a > a->size / 2)
		return (rot_a - a->size);
	return (rot_a);
}

static void	get_min_rots(t_dequeue *a, t_dequeue *b, int *best_a, int *best_b)
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
	int		rots[2];
	int		min_index;
	t_node	*curr;

	rots[0] = 0;
	rots[1] = 0;
	while (b->size != 0)
	{
		get_min_rots(a, b, &rots[0], &rots[1]);
		rotate_deqs(a, b, cmds, rots);
	}
	min_index = 0;
	curr = a->head;
	while (curr)
	{
		if (curr->next != NULL && curr->value > curr->next->value)
			break ;
		curr = curr->next;
		++min_index;
	}
	++min_index;
	if (min_index < a->size)
	{
		if (min_index > a->size / 2)
			rotate_a(a, cmds, min_index - a->size);
		else
			rotate_a(a, cmds, min_index);
	}
}
