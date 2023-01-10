/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:43 by soohong           #+#    #+#             */
/*   Updated: 2023/01/10 23:16:49 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	get_big_pivot()
// {

// }

// static void	get_small_pivot()
// {

// }

static void	quicksort_swap(int *a, int *b)
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
	int	temp;

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
				quicksort_swap(&array[i], &array[j]);
		}
		quicksort_swap(&array[pivot], &array[j]);
		quicksort(array, left, j - 1);
		quicksort(array, j + 1, right);
	}
}

void	quick_sort(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	int		*array;
	t_node	*current;
	int		i;
	int		big_pivot;
	int		small_pivot;

	array = (int *)malloc(sizeof(int) * (a->size));
	current = a->head;
	i = 0;
	while (current)
	{
		array[i] = current->value;
		i++;
		current = current->next;
	}
	quicksort(array, array[0], array[i]);
}
