#include "push_swap.h"

	static void	swap(t_dequeue *queue)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = queue->head;
	node_b = queue->head->next;
	node_a->prev = node_b;
	node_a->next = node_b->next;
	node_b->prev = NULL;
	node_b->next = node_a;
	queue->head = node_b;
}

void	sa(t_dequeue *a, t_cmds *cmds)
{
	if (a->size < 2)
		return ;
	swap(a);
	cmd_node(cmds, CMD_SA);
}

void	sb(t_dequeue *b, t_cmds *cmds)
{
	if (b->size < 2)
		return ;
	swap(b);
	cmd_node(cmds, CMD_SB);
}

void	ss(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	swap(a);
	swap(b);
	cmd_node(cmds, CMD_SS);
}