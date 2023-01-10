#include "push_swap.h"

static void	rotate(t_dequeue *deq)
{
	t_node	*new_tail;

	if (deq->size == 0)
		return ;
	new_tail = deq->head;
	deq->head = deq->head->next;
	deq->head->prev = NULL;
	deq->tail->next = new_tail;
	new_tail->prev = deq->tail;
	new_tail->next = NULL;
	deq->tail = new_tail;
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
