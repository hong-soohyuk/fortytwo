/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:39:08 by soohong           #+#    #+#             */
/*   Updated: 2023/01/11 19:33:56 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static void	rotate_a(t_dequeue *a, t_cmds *cmds, int rot_a)
{
	while (rot_a > 0)
	{
		ra(a, cmds);
		++rot_a;
	}
	while (rot_a < 0)
	{
		rra(a, cmds);
		--rot_a;
	}
}

static void	rotate_b(t_dequeue *b, t_cmds *cmds, int rot_b)
{
	while (rot_b > 0)
	{
		rb(b, cmds);
		++rot_b;
	}
	while (rot_b < 0)
	{
		rrb(b, cmds);
		--rot_b;
	}
}

void	rotate_deqs(t_dequeue *a, t_dequeue *b, t_cmds *cmds, int	*bests)
{
	int	rot_a;
	int	rot_b;

	rot_a = bests[0];
	rot_b = bests[1];
	while (rot_a > 0 && rot_b > 0)
	{
		rr(a, b, cmds);
		--rot_a;
		--rot_b;
	}
	while (rot_b < 0 && rot_b < 0)
	{
		rrr(a, b, cmds);
		++rot_a;
		++rot_b;
	}
	if (rot_a != 0)
		rotate_a(a, cmds, rot_a);
	if (rot_b != 0)
		rotate_b(b, cmds, rot_b);
	pa(a, b, cmds);
}
