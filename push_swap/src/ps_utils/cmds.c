/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:18:34 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 12:19:34 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	merge_cmds(t_node **head, t_node *del, int value_of_cmd)
{
	if (*head == NULL || del == NULL)
		return ;
	if (del->next != NULL)
		del->next->value = value_of_cmd;
	if (*head == del)
		*head = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
}

void	cmd_optimize(t_cmds *cmds)
{
	t_node	*curr;

	curr = cmds->head;
	while (curr)
	{
		if (curr->next != NULL
			&& curr->value == CMD_RA && curr->next->value == CMD_RB)
			merge_cmds(&cmds->head, curr, CMD_RR);
		else if (curr->next != NULL
			&& curr->value == CMD_RB && curr->next->value == CMD_RA)
			merge_cmds(&cmds->head, curr, CMD_RR);
		else if (curr->next != NULL
			&& curr->value == CMD_RRA && curr->next->value == CMD_RRB)
			merge_cmds(&cmds->head, curr, CMD_RRR);
		else if (curr->next != NULL
			&& curr->value == CMD_RRB && curr->next->value == CMD_RRA)
			merge_cmds(&cmds->head, curr, CMD_RRR);
		curr = curr->next;
	}
}

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

void	stdout_cmds(t_cmds *cmds)
{
	t_node	*cmd;
	t_node	*next;

	cmd_optimize(cmds);
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
