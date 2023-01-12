void	stdout_queue(t_dequeue *a, t_dequeue *b)
{
	t_node	*current_a;
	t_node	*current_b;

	if (!a || !b)
		return ;
	current_a = a->head;
	current_b = b->head;
	printf("|	A			|	B			|\n");
	while (current_a && current_b)
	{
		printf("|	%d			|	%d			|\n",
				current_a->value, current_b->value);
			current_a = current_a->next;
			current_b = current_b->next;
	}
	while (current_a || current_b)
	{
		if (current_a == NULL)
		{
			printf("|				|	%d			|\n", current_b->value);
			current_b = current_b->next;
		}
		else if (current_b == NULL)
		{
			printf("|	%d			|				|\n", current_a->value);
			current_a = current_a->next;
		}
		else if (current_a == NULL && current_b == NULL)
		{
			printf("|	end			|	end			|\n");
			break ;
		}
	}
	printf("|	end			|	end			|\n");
}
