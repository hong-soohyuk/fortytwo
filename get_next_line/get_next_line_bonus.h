/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:00:40 by soohong           #+#    #+#             */
/*   Updated: 2022/12/20 20:50:56 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_node
{
	int					fd;
	char				*read_line;
	struct s_fd_node	*next;
}	t_fd_node;

char	*get_next_line(int fd);
char	*free_return(t_fd_node **lst, t_fd_node *node, void *mem1, void *mem2);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
void	delete_node(t_fd_node **head, t_fd_node *node);

#endif
