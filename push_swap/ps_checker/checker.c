/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:18:29 by soohong           #+#    #+#             */
/*   Updated: 2023/01/18 12:03:52 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/checker.h"

static void	select_cmd(t_dequeue *a, t_dequeue *b, char *read_line)
{
	if (!ps_strcmp(read_line, "sa\n"))
		sa(a);
	else if (!ps_strcmp(read_line, "sb\n"))
		sb(b);
	else if (!ps_strcmp(read_line, "ss\n"))
		ss(a, b);
	else if (!ps_strcmp(read_line, "pa\n"))
		pa(a, b);
	else if (!ps_strcmp(read_line, "pb\n"))
		pb(a, b);
	else if (!ps_strcmp(read_line, "ra\n"))
		ra(a);
	else if (!ps_strcmp(read_line, "rb\n"))
		rb(b);
	else if (!ps_strcmp(read_line, "rr\n"))
		rr(a, b);
	else if (!ps_strcmp(read_line, "rra\n"))
		rra(a);
	else if (!ps_strcmp(read_line, "rrb\n"))
		rrb(b);
	else if (!ps_strcmp(read_line, "rrr\n"))
		rrr(a, b);
	else
		exit_safe(a, b, EXIT_FAILURE);
}

static void	process_cmds(t_dequeue *a, t_dequeue *b)
{
	char	*read_line;

	read_line = get_next_line(0);
	while (read_line)
	{
		select_cmd(a, b, read_line);
		read_line = get_next_line(0);
	}	
}

int	is_sorted(t_dequeue *a)
{
	t_node	*curr;

	if (a->size == 1)
		return (1);
	curr = a->head;
	while (curr)
	{
		if (curr->next != NULL && curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_dequeue	*a;
	t_dequeue	*b;
	a = (t_dequeue *)malloc(sizeof(t_dequeue));
	b = (t_dequeue *)malloc(sizeof(t_dequeue));
	init_dequeue(a, b, argv, argc);
	if (argc == 1)
		exit_safe(a, b, EXIT_SUCCESS);
	process_cmds(a, b);
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit_safe(a, b, EXIT_SUCCESS);
}
