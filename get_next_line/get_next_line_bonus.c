/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:00:15 by soohong           #+#    #+#             */
/*   Updated: 2023/03/06 19:08:47 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_fd_node	*gnl_lstadd_front(t_fd_node **lst, int fd)
{
	t_fd_node	*fd_node;

	if (lst == NULL)
		return (0);
	fd_node = (t_fd_node *)malloc(sizeof(t_fd_node));
	if (fd_node == NULL)
		return (0);
	fd_node->fd = fd;
	fd_node->read_line = NULL;
	if (*lst)
		fd_node->next = *lst;
	else
		fd_node->next = NULL;
	*lst = fd_node;
	return (fd_node);
}

static char	*get_buffer_read(int fd, char *read_line)
{
	char	*buffer;
	int		rd_size;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	buffer[0] = '\0';
	rd_size = -1;
	while (!gnl_strchr(buffer, '\n') && rd_size != 0)
	{
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size == -1)
			return (free_return(NULL, NULL, read_line, buffer));
		buffer[rd_size] = '\0';
		read_line = gnl_strjoin(read_line, buffer);
		if (read_line == NULL)
			return (free_return(NULL, NULL, buffer, NULL));
	}
	free_return(NULL, NULL, buffer, NULL);
	return (read_line);
}

static char	*get_return_val(char *read_line)
{
	int		byte_for_n;
	char	*return_val;
	size_t	i;

	i = 0;
	if (read_line[i] == '\0')
		return (0);
	while (read_line[i] != '\0' && read_line[i] != '\n')
		++i;
	byte_for_n = read_line[i] == '\n';
	return_val = (char *)malloc(sizeof(char) * (i + byte_for_n + 1));
	if (return_val == NULL)
		return (free_return(NULL, NULL, read_line, NULL));
	i = -1;
	if (byte_for_n)
		while (read_line[++i] != '\n')
			return_val[i] = read_line[i];
	else
		while (read_line[++i] != '\0')
			return_val[i] = read_line[i];
	if (byte_for_n)
		return_val[i++] = '\n';
	return_val[i] = '\0';
	return (return_val);
}

static char	*reset_read_line(t_fd_node **fd_list, t_fd_node *fd_node)
{
	char	*read_line;
	char	*prev;
	size_t	i;
	size_t	j;

	read_line = fd_node->read_line;
	i = 0;
	while (read_line[i] != '\0' && read_line[i] != '\n')
		++i;
	if (read_line[i] == '\0')
		return (free_return(fd_list, fd_node, read_line, NULL));
	prev = (char *)malloc(sizeof(char) * (gnl_strlen(read_line) - i + 1));
	if (prev == NULL)
		return (free_return(fd_list, fd_node, read_line, NULL));
	++i;
	j = 0;
	while (read_line[i] != '\0')
		prev[j++] = read_line[i++];
	prev[j] = '\0';
	free_return(NULL, NULL, read_line, NULL);
	fd_node->read_line = prev;
	return (prev);
}

char	*get_next_line(int fd)
{
	static t_fd_node	*fd_list;
	t_fd_node			*fd_node;
	char				*return_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (fd_list == NULL)
		fd_node = gnl_lstadd_front(&fd_list, fd);
	else
	{
		fd_node = fd_list;
		while (fd_node && fd_node->fd != fd)
				fd_node = fd_node->next;
		if (fd_node == NULL)
			fd_node = gnl_lstadd_front(&fd_list, fd);
	}
	fd_node->read_line = get_buffer_read(fd, fd_node->read_line);
	if (fd_node->read_line == NULL)
		return (free_return(&fd_list, fd_node, NULL, NULL));
	return_val = get_return_val(fd_node->read_line);
	if (return_val == NULL)
		return (free_return(&fd_list, fd_node, fd_node->read_line, NULL));
	reset_read_line(&fd_list, fd_node);
	return (return_val);
}
