/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:31 by soohong           #+#    #+#             */
/*   Updated: 2023/01/03 18:56:37 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int	value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int	size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_dequeue;

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define ATOI_FAILURE 3000000000

char	**ps_split(char const *s, char c);
void	ps_putstr(char *s);
void	init_dequeue(t_dequeue *a, char **argv, int argc);
long	ps_atoi(const char *str);
void	exit_safe(t_dequeue *a, t_dequeue *b, int exit_code);

#endif
