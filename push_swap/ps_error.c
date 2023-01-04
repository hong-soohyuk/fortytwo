#include "push_swap.h"

int	error_terminate(t_stack *a, t_stack *b)
{
	t_node	*next;
	t_node	*current;
	int		i;

	i = -1;
	while (++i < 2)
	{
		if (i == 0 && a)
			current = a->head;
		else if (i == 1 && b)
			current = b->head;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	write(2, &"Error\n", 6);
	exit(1);
}