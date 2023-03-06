/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:00:15 by soohong           #+#    #+#             */
/*   Updated: 2023/03/06 19:08:29 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		{
			if (read_line)
				free_return(read_line);
			return (free_return(buffer));
		}
		buffer[rd_size] = '\0';
		read_line = gnl_strjoin(read_line, buffer);
		if (read_line == NULL)
			return (free_return(buffer));
	}
	free_return(buffer);
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
		return (free_return(read_line));
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

static char	*reset_read_line(char *read_line)
{
	char	*prev;
	size_t	i;
	size_t	j;

	i = 0;
	while (read_line[i] != '\0' && read_line[i] != '\n')
		++i;
	if (read_line[i] == '\0')
		return (free_return(read_line));
	prev = (char *)malloc(sizeof(char) * (gnl_strlen(read_line) - i + 1));
	if (prev == NULL)
		return (free_return(read_line));
	++i;
	j = 0;
	while (read_line[i] != '\0')
		prev[j++] = read_line[i++];
	prev[j] = '\0';
	free_return(read_line);
	return (prev);
}

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*return_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_line = get_buffer_read(fd, read_line);
	if (read_line == NULL)
		return (0);
	return_val = get_return_val(read_line);
	read_line = reset_read_line(read_line);
	return (return_val);
}
