/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:19:18 by soohong           #+#    #+#             */
/*   Updated: 2023/01/31 14:56:45 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 5
# define ATOI_FAILURE 3000000000
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_dequeue
{
	int				min;
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_dequeue;

char	*get_next_line(int fd);
char	*free_return(void *memory);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
char	**ps_split(char const *s, char c);
long	ps_atoi(const char *str);
int		ps_strcmp(char *s1, char *s2);
void	sa(t_dequeue *a);
void	sb(t_dequeue *b);
void	ss(t_dequeue *a, t_dequeue *b);
void	pa(t_dequeue *a, t_dequeue *b);
void	pb(t_dequeue *a, t_dequeue *b);
void	ra(t_dequeue *a);
void	rb(t_dequeue *b);
void	rr(t_dequeue *a, t_dequeue *b);
void	rra(t_dequeue *a);
void	rrb(t_dequeue *b);
void	rrr(t_dequeue *a, t_dequeue *b);
void	init_dequeue(t_dequeue *a, t_dequeue *b, char **argv, int argc);
void	exit_safe(t_dequeue *a, t_dequeue *b, int exit_code);

#endif
