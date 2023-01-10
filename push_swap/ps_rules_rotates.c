#include "push_swap.h"

static void	rotate(t_dequeue *target)
{
	t_node	*new_tail;

	new_tail = target->head;
	target->head = target->head->next;
	target->head->prev = NULL;
	target->tail->next = new_tail;
	new_tail->prev = target->tail;
	new_tail->next = NULL;
	target->tail = new_tail;
}

void	ra(t_dequeue *a, t_cmds *cmds)
{
	rotate(a);
	cmd_node(cmds, CMD_RA);
}

void	rb(t_dequeue *b, t_cmds *cmds)
{
	rotate(b);
	cmd_node(cmds, CMD_RB);
}

void	rr(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	rotate(a);
	rotate(b);
	cmd_node(cmds, CMD_RR);
}