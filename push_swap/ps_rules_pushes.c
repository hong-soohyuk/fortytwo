#include "push_swap.h"
static void	push(t_dequeue *src, t_dequeue *dest)
{
	t_node	*swap_node;

	swap_node = src->head;
	src->head = src->head->next;
	src->head->prev = NULL;
	swap_node->prev = NULL;
	swap_node->next = dest->head;
	dest->head = swap_node;
}

void	pa(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	if (b->size == 0)
		return ;
	push(b, a);
	cmd_node(cmds, CMD_PA);
}

void	pb(t_dequeue *b, t_dequeue *a, t_cmds *cmds)
{
	if (a->size == 0)
		return ;
	push(a, b);
	cmd_node(cmds, CMD_PB);
}