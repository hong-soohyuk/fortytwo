#include "push_swap.h"

void	sa(t_dequeue *a, t_cmds *cmds)
{
	t_node	*node_a;
	t_node	*node_b;
	
	if (a->size < 2)
		return ;
	node_a = a->head;
	node_b = a->head->next;
	node_a->prev = node_b;
	node_a->next = node_b->next;
	node_b->prev = NULL;
	node_b->next = node_a;
	a->head = node_b;
}

void	sb(t_dequeue *b, t_cmds *cmds)
{
	(void)b;
	write(1, &"sb\n", 3);
}

void	ss(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{

	(void)a;
	(void)b;
	write(1, &"ss\n", 3);
}