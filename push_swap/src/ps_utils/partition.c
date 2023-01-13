/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:43 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 14:08:19 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	quicksort(int *array, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	if (left < right)
	{
		pivot = left;
		i = left;
		j = right;
		while (i < j)
		{
			while (array[i] <= array[pivot] && i < right)
				i++;
			while (array[j] > array[pivot])
				j--;
			if (i < j)
				sort_swap(&array[i], &array[j]);
		}
		sort_swap(&array[pivot], &array[j]);
		quicksort(array, left, j - 1);
		quicksort(array, j + 1, right);
	}
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
		sort_under_six(a, b, cmds, 0);
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
	if (a->size > 2 && a->size < 6)
		sort_under_six(a, b, cmds, array[2]);
	else if (a->size == 2)
		sort_under_six(a, b, cmds, -1);
	else
		categorize(a, b, cmds, pivots);
	free(array);
}
