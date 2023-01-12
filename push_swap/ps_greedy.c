/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:39:08 by soohong           #+#    #+#             */
/*   Updated: 2023/01/12 12:03:55 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

static int	find_null_loc(t_dequeue *a, int btoa)
{
	t_node	*curr;

	curr = a->head;
	if (a->tail->value > btoa && curr->value > btoa
		&& a->tail->value > curr->value)
		return (1);
	if (a->tail->value < btoa && curr->value > btoa
		&& a->tail->value < curr->value)
		return (1);
	if (a->tail->value < btoa && curr->value < btoa
		&& a->tail->value > curr->value)
		return (1);
	return (0);
}

static int	get_min_ra(t_dequeue *a, int btoa)
{
	t_node	*curr;
	int		rot_a;

	curr = a->head;
	rot_a = 0;
	while (curr)
	{
		if (curr->prev == NULL && find_null_loc(a, btoa))
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
		rot_a = get_min_ra(a, curr_b->value);
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

static	void	ascending_sort(t_dequeue *a, t_cmds *cmds)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = a->head;
	while (curr->value != a->min)
	{
		++i;
		curr = curr->next;
	}
	if (i > a->size / 2)
		while (a->head->value != a->min)
			rra(a, cmds);
	else
		while (a->head->value != a->min)
			ra(a, cmds);
}

void	greedy_sort(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	int		rots[2];

	while (b->size != 0)
	{
		rots[0] = 0;
		rots[1] = 0;
		get_min_rots(a, b, &rots[0], &rots[1]);
		rotate_deqs(a, b, cmds, rots);
		printf("after one sort \n");
		stdout_queue(a, b);
		printf("\n");
	}
	ascending_sort(a, cmds);
}
