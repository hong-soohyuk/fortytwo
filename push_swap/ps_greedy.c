/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:39:08 by soohong           #+#    #+#             */
/*   Updated: 2023/01/12 23:47:51 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

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
		if (curr->prev != NULL && curr->prev->value > btoa
			&& curr->value > btoa && curr->prev->value > curr->value)
			break ;
		if (curr->prev != NULL && curr->prev->value < btoa
			&& curr->value > btoa && curr->prev->value < curr->value)
			break ;
		if (curr->prev != NULL && curr->prev->value < btoa
			&& curr->value < btoa && curr->prev->value > curr->value)
			break ;
		curr = curr->next;
		rot_a++;
	}
	if (rot_a > a->size / 2)
		return (rot_a - a->size);
	else
		return (rot_a);
}

static void	get_min_rots(t_dequeue *a, t_dequeue *b, int *bests)
{
	t_node	*curr_b;
	int		min_rots;
	int		rot_a;
	int		i;
	int		rot_b;

	curr_b = b->head;
	min_rots = 2147483647;
	i = 0;
	rot_b = 0;
	while (curr_b)
	{
		rot_a = get_min_ra(a, curr_b->value);
		if (i > b->size / 2)
			rot_b = (i - b->size);
		else
			rot_b = i;
		if (absolute(rot_a) + absolute(rot_b) < min_rots)
		{
			min_rots = absolute(rot_a) + absolute(rot_b);
			bests[0] = rot_a;
			bests[1] = rot_b;
		}
		curr_b = curr_b->next;
		i++;
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
		get_min_rots(a, b, rots);
		rotate_deqs(a, b, cmds, rots);
	}
	ascending_sort(a, cmds);
}
