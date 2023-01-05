#include "push_swap.h"

void	ra(t_dequeue *a, t_cmds *cmds)
{
	(void)a;
	(void)cmds;

	write(1, &"ra\n", 3);
}

void	rb(t_dequeue *b, t_cmds *cmds)
{
	
	(void)cmds;
	(void)b;
	write(1, &"rb\n", 3);
}

void	rr(t_dequeue *a, t_dequeue *b, t_cmds *cmds)
{
	(void)cmds;
	(void)a;
	(void)b;
	
	write(1, &"rr\n", 3);
}