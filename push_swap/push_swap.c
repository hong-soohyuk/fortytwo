/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:47:16 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 00:39:40 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_dequeue	*a;
	t_dequeue	*b;
	t_cmds		*cmds;

	if (argc == 1)
		exit_safe(NULL, NULL, EXIT_FAILURE);
	a = (t_dequeue *)malloc(sizeof(t_dequeue));
	b = (t_dequeue *)malloc(sizeof(t_dequeue));
	cmds = (t_cmds *)malloc(sizeof(t_cmds));
	init_dequeue(a, b, argv, argc);
	if (argc == 4)
		hardsort(a, cmds);
	else
	{
		partition(a, b, cmds);
		greedy_sort(a, b, cmds);
	}
	stdout_cmds(cmds);
	exit_safe(a, b, EXIT_SUCCESS);
}
