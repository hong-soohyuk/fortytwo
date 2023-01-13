/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:43 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 13:09:20 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_for_five(t_dequeue *a, t_dequeue *b, t_cmds *cmds, int pivot)
{
	int	i;
	int	pb_count;

	i = 0;
	pb_count = 1 + (a->size == 5);
	while (i < a->size)
	{
		if (pb_count == 0)
			break ;
		if (a->tail->value < pivot)
			rra(a, cmds);
		if (a->head->value < pivot)
		{
			pb(a, b, cmds);
			--pb_count;
		}
		else
			ra(a, cmds);
		i++;
	}
	hardsort(a, cmds);
	if (b->head->next != NULL && b->head->value < b->head->next->value)
		sb(b, cmds);
	if (a->size == 5)
		pa(a, b, cmds);
	pa(a, b, cmds);
}

void	hardsort(t_dequeue *a, t_cmds *cmds)
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

static void	categorize(t_dequeue *a, t_dequeue *b, t_cmds *cmds, int *pivots)
{
	int	i;
	int	length;

	i = -1;
	length = a->size;
	while (++i < length)
	{
		if (a->head->value > pivots[0])
			ra(a, cmds);
		else if (a->head->value > pivots[1] && a->head->value <= pivots[0])
			pb(a, b, cmds);
		else if (a->head->value <= pivots[1])
		{
			pb(a, b, cmds);
			rb(b, cmds);
		}
	}
	while (a->size > 3)
		pb(a, b, cmds);
	if (a->size == 2 && a->head->value > a->head->next->value)
		sa(a, cmds);
	else if (a->size == 3)
		hardsort(a, cmds);
}

void	partition(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	int		*array;
	t_node	*current;
	int		i;
	int		pivots[2];

	array = (int *)malloc(sizeof(int) * (a->size));
	current = a->head;
	i = -1;
	while (current && ++i < a->size)
	{
		array[i] = current->value;
		current = current->next;
	}
	quicksort(array, 0, a->size - 1);
	a->min = array[0];
	pivots[0] = array[(a->size / 3) * 2];
	pivots[1] = array[a->size / 3];
	if (a->size == 5)
		sort_for_five(a, b, cmds, array[2]);
	else
		categorize(a, b, cmds, pivots);
	free(array);
}
