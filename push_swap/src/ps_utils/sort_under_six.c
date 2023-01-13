/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:41:15 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 17:06:26 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	hardsort_for_three(t_dequeue *a, t_cmds *cmds)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->tail->value;
	if (first < second && second > third && first < third)
	{
		sa(a, cmds);
		ra(a, cmds);
	}
	else if (first > second && second < third && third > first)
		sa(a, cmds);
	else if (first > third && second > third && first < second)
		rra(a, cmds);
	else if (first > second && second > third && first > third)
	{
		sa(a, cmds);
		rra(a, cmds);
	}
	else if (first > second && second < third && first > third)
		ra(a, cmds);
}

static void	hardsort_for_four(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	if (a->head->value == a->min)
		pb(a, b, cmds);
	if (a->tail->value == a->min)
	{
		rra(a, cmds);
		pb(a, b, cmds);
	}
	if (a->head->next->value == a->min)
	{
		ra(a, cmds);
		pb(a, b, cmds);
	}
	if (a->tail->prev->value == a->min)
	{
		ra(a, cmds);
		ra(a, cmds);
		pb(a, b, cmds);
	}
	hardsort_for_three(a, cmds);
	pa(a, b, cmds);
}

static void	hardsort_for_five(t_dequeue *a, t_dequeue *b, int m, t_cmds *cmds)
{
	int	i;
	int	pb_count;

	i = 0;
	pb_count = 2;
	while (i < a->size)
	{
		if (pb_count == 0)
			break ;
		if (a->tail->value < m)
			rra(a, cmds);
		if (a->head->value < m)
		{
			pb(a, b, cmds);
			--pb_count;
		}
		else
			ra(a, cmds);
		i++;
	}
	hardsort_for_three(a, cmds);
	if (b->head->value < b->head->next->value)
		sb(b, cmds);
	pa(a, b, cmds);
	pa(a, b, cmds);
}

void	sort_under_six(t_dequeue *a, t_dequeue *b, t_cmds *cmds, int middle)
{
	if (a->size == 2 && a->head->value > a->head->next->value)
		sa(a, cmds);
	if (a->size == 3)
		hardsort_for_three(a, cmds);
	if (a->size == 4)
		hardsort_for_four(a, b, cmds);
	if (a->size == 5)
		hardsort_for_five(a, b, middle, cmds);
}
