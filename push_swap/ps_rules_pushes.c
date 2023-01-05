#include "push_swap.h"

void	pa(t_dequeue *a, t_cmds *cmds)
{
	(void)a;
	(void)cmds;

	write(1, &"pa\n", 3);
}

void	pb(t_dequeue *b, t_cmds *cmds)
{
	(void)b;
	(void)cmds;
	
	write(1, &"pb\n", 3);
}