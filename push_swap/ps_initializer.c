/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:34 by soohong           #+#    #+#             */
/*   Updated: 2023/01/03 18:58:20 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	enqueue(t_stack * a, int value)
{
	t_node *new;
	t_node *current;

	new = (t_node *)malloc(sizeof(t_node));
	new->prev = NULL;
	new->next = NULL;
	new->value = value;
	if (a->size == 0)
	{
		a->head = new;
		a->tail = new;
	}
	else
	{
		current = a->head;
		while (current)
		{
			if (current->value == value)
				return (error_terminate(a, NULL)); // free a
			else
				current = current->next;
		}
		a->tail->next = new;
		new->prev = a->tail;
		a->tail = new;
	}
	a->size++;
	return (1);
}
// void	dequeue(t_stack * a, int value) {}

static int check_enqueue(t_stack *a, char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		if (enqueue(a, ps_atoi(table[i])) == 0)
			return (0);
	return (1);
}

void	init_stacks(t_stack *a, char **argv, int argc)
{
	int		i;
	char	**split_table;

	i = 0;
	while (++i < argc)
	{
		split_table = ps_split(argv[i], ' ');
		if (check_enqueue(a, split_table) == 0)
			return ;
	}
}