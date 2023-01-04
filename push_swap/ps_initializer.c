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

static void	enqueue(t_stack * a, int value)
{
	t_node *new;

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
		a->tail->next = new;
		new->prev = a->tail;
		a->tail = new;
	}
	a->size++;
}
// void	dequeue(t_stack * a, int value){}

static void check_enqueue(t_stack *a, char **table)
{
	//duplicate check
	int	i;

	i = -1;
	while (table[++i])
		enqueue(a, ps_atoi(table[i]));

}

static void	extract_nbr(t_stack *a, char **argv, int argc)
{
	int	i;
	char	**split_table;

	i = 0;
	
	while (++i < argc)
	{
		split_table = ps_split(argv[i], ' ');
		check_enqueue(a, split_table);
	}
}

void	init_stacks(t_stack *a, char **argv, int argc)
{
	extract_nbr(a, argv, argc);
}