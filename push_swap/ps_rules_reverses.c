#include "push_swap.h"

void	rra(t_dequeue *a, t_cmds *cmds)
{
	(void)a;
	(void)cmds;

	write(1, &"rra\n", 4);
}

void	rrb(t_dequeue *b, t_cmds *cmds)
{
	(void)cmds;
	
	(void)cmds;
	(void)b;
	write(1, &"rrb\n", 4);
}

void	rrr(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	(void)cmds;
	
	(void)a;
	(void)b;
	write(1, &"rrr\n", 4);
}