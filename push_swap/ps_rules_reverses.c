#include "push_swap.h"

static void	reverse(t_dequeue *target)
{
	t_node *new_head;

	new_head = target->tail;
	target->tail = target->tail->prev;
	target->tail->next = NULL;
	new_head->prev = NULL;
	new_head->next = target->head;
	target->head->prev = new_head;
	target->head = new_head;
}
void	rra(t_dequeue *a, t_cmds *cmds)
{
	reverse(a);
	cmd_node(cmds, CMD_RRA);
}

void	rrb(t_dequeue *b, t_cmds *cmds)
{
	reverse(b);
	cmd_node(cmds, CMD_RRB);
}

void	rrr(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	reverse(a);
	reverse(b);
	cmd_node(cmds, CMD_RRR);
}