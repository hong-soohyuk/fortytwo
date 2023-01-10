#include "push_swap.h"

static void	push(t_dequeue *src, t_dequeue *dest)
{
	t_node	*swap_node;

	swap_node = src->head;
	if (src->size == 1)
	{
		src->head = NULL;
		src->tail = NULL;
	}
	else
	{
		src->head = src->head->next;
		src->head->prev = NULL;
	}
	if (dest->size == 0)
	{
		swap_node->next = NULL;
		dest->head = swap_node;
		dest->tail = swap_node;
	}
	else
	{
		swap_node->next = dest->head;
		dest->head->prev = swap_node;
		dest->head = swap_node;
	}
	src->size--;
	dest->size++;
}

void	pa(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	if (b->size == 0)
		return ;
	push(b, a);
	cmd_node(cmds, CMD_PA);
}

void	pb(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	if (a->size == 0)
		return ;
	push(a, b);
	cmd_node(cmds, CMD_PB);
}