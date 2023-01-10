#include "push_swap.h"

static void	free_deq(t_dequeue *q)
{
	t_node	*next;
	t_node	*current;

	current = q->head;
	while (current)
	{
		next = current->next;
		printf("%d is freed \n", current->value);
		free(current);
		current = next;
	}
	free(q);
}

void	exit_safe(t_dequeue *a, t_dequeue *b, int exit_code)
{
	if (a)
		free_deq(a);
	if (b)
		free_deq(b);
	if (exit_code)
		write(2, &"Error\n", 6);
	// system("leaks push_swap");
	exit(exit_code);
}
