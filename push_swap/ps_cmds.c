/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:18:34 by soohong           #+#    #+#             */
/*   Updated: 2023/01/10 15:30:23 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stdout_cmd(int cmd)
{
	if (cmd == CMD_SA)
		write(1, &"sa\n", 3);
	else if (cmd == CMD_SB)
		write(1, &"sb\n", 3);
	else if (cmd == CMD_SS)
		write(1, &"ss\n", 3);
	else if (cmd == CMD_PA)
		write(1, &"pa\n", 3);
	else if (cmd == CMD_PB)
		write(1, &"pb\n", 3);
	else if (cmd == CMD_RA)
		write(1, &"ra\n", 3);
	else if (cmd == CMD_RB)
		write(1, &"rb\n", 3);
	else if (cmd == CMD_RR)
		write(1, &"rr\n", 3);
	else if (cmd == CMD_RRA)
		write(1, &"rra\n", 4);
	else if (cmd == CMD_RRB)
		write(1, &"rrb\n", 4);
	else if (cmd == CMD_RRR)
		write(1, &"rrr\n", 4);
	else
		write(1, &"??\n", 3);
}

void	stdout_cmds(t_cmds *cmds)
{
	t_node	*cmd;
	t_node	*next;

	cmd = cmds->head;
	while (cmd)
	{
		next = cmd->next;
		stdout_cmd(cmd->value);
		free(cmd);
		cmd = next;
	}
	free(cmds);
}

// void	cmd_optimize(){}

void	cmd_node(t_cmds *cmds, int cmd)
{
	t_node	*new;
	t_node	*current;
	
	new = (t_node *)malloc(sizeof(t_node));
	new->value = cmd;
	new->prev = NULL;
	new->next = NULL;
	if (cmds->head == NULL)
	{
		cmds->head = new;
		cmds->tail = new;
	}
	else
	{
		current = cmds->head;
		while (current)
			current = current->next;
		cmds->tail->next = new;
		new->prev = cmds->tail;
		cmds->tail = new;
	}
}