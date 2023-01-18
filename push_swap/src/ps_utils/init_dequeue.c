/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dequeue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:34 by soohong           #+#    #+#             */
/*   Updated: 2023/01/18 12:15:21 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	free_table(char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
}

static void	enqueue(t_dequeue *a, t_node *new, char **table)
{
	t_node	*current;

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
			if (current->value == new->value)
			{
				free_table(table);
				exit_safe(a, NULL, EXIT_FAILURE);
			}
			else
				current = current->next;
		}
		a->tail->next = new;
		new->prev = a->tail;
		a->tail = new;
	}
	(a->size)++;
}

static void	init_node(t_dequeue *a, long value, char **table)
{
	t_node	*new;

	if (value == ATOI_FAILURE)
	{
		free_table(table);
		exit_safe(a, NULL, EXIT_FAILURE);
	}
	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
	{
		free_table(table);
		exit_safe(a, NULL, EXIT_FAILURE);
	}
	new->prev = NULL;
	new->next = NULL;
	new->value = value;
	enqueue(a, new, table);
}

void	init_dequeue(t_dequeue *a, t_dequeue *b, char **argv, int argc)
{
	int		i;
	int		j;
	char	**table;

	a->size = 0;
	a->head = NULL;
	a->tail = NULL;
	b->size = 0;
	b->head = NULL;
	b->tail = NULL;
	i = 0;
	while (++i < argc)
	{
		table = ps_split(argv[i], ' ');
		j = -1;
		while (table[++j])
			init_node(a, ps_atoi(table[j]), table);
		if (j == 0)
		{
			free_table(table);
			exit_safe(a, NULL, EXIT_FAILURE);
		}
		free_table(table);
	}
}
