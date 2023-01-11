/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:31 by soohong           #+#    #+#             */
/*   Updated: 2023/01/12 00:11:15 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_dequeue
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_dequeue;

enum e_cmd{
	CMD_SA,
	CMD_SB,
	CMD_SS,
	CMD_PA,
	CMD_PB,
	CMD_RA,
	CMD_RB,
	CMD_RR,
	CMD_RRA,
	CMD_RRB,
	CMD_RRR
};

typedef struct s_cmds
{
	struct s_node	*head;
	struct s_node	*tail;
}	t_cmds;

# define ATOI_FAILURE 3000000000

void	stdout_queue(t_dequeue *a, t_dequeue *b);
char	**ps_split(char const *s, char c);
long	ps_atoi(const char *str);
void	init_dequeue(t_dequeue *a, t_dequeue *b, char **argv, int argc);
int		absolute(int a);
void	exit_safe(t_dequeue *a, t_dequeue *b, int exit_code);
void	partition(t_dequeue *a, t_dequeue *b, t_cmds *cmds);
void	rotate_a(t_dequeue *a, t_cmds *cmds, int rot_a);
void	rotate_deqs(t_dequeue *a, t_dequeue *b, t_cmds *cmds, int *bests);
void	greedy_sort(t_dequeue *a, t_dequeue *b, t_cmds *cmds);
void	cmd_node(t_cmds *cmds, int cmd);
void	stdout_cmds(t_cmds *cmds);
void	sa(t_dequeue *a, t_cmds *cmds);
void	sb(t_dequeue *b, t_cmds *cmds);
void	ss(t_dequeue *a, t_dequeue *b, t_cmds *cmds);
void	pa(t_dequeue *a, t_dequeue *b, t_cmds *cmds);
void	pb(t_dequeue *a, t_dequeue *b, t_cmds *cmds);
void	ra(t_dequeue *a, t_cmds *cmds);
void	rb(t_dequeue *b, t_cmds *cmds);
void	rr(t_dequeue *a, t_dequeue *b, t_cmds *cmds);
void	rra(t_dequeue *a, t_cmds *cmds);
void	rrb(t_dequeue *b, t_cmds *cmds);
void	rrr(t_dequeue *a, t_dequeue *b, t_cmds *cmds);
#endif
