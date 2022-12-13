/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:19:16 by soohong           #+#    #+#             */
/*   Updated: 2022/12/13 17:20:57 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_read_line(int fd, char *read_line)
{
	char	*buffer;
	int		rd_size;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	rd_size = 1;
	while (!gnl_strchr(buffer, '\n') && rd_size != 0)
	{
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size == -1)
		{
			free(buffer);
			buffer = 0;
			return (0);
		}
		buffer[rd_size] = 0;
		read_line = gnl_strjoin(read_line, buffer);
	}
	free(buffer);
	return (read_line);
}

static char	*get_line(char *read_line)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (read_line == 0)
		return (0);
	while (read_line[i] != 0 && read_line[i] != '\n')
		++i;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (temp == 0)
		return (0);
	i = 0;
	while (read_line[i] != 0 && read_line[i] != '\n')
	{
		temp[i] = read_line[i];
		++i;
	}
	temp[i] = '\0';
	return (temp);
}

char	*reset_read_line(char *read_line)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (read_line[i] != 0 && read_line[i] != '\n')
		++i;
	if (read_line[i] == 0)
	{
		free(read_line);
		read_line = 0;
		return (0);
	}
	temp = (char *)malloc(sizeof(char) * (gnl_strlen(read_line - i + 1)));
	if (temp == 0)
		return (0);
	++i;
	j = 0;
	while (read_line[i] != 0)
		temp[j++] = read_line[i++];
	temp[j] = '\0';
	free(read_line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*return_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_line = get_read_line(fd, read_line);
	if (read_line == 0)
		return (0);
	return_val = get_line(read_line);
	read_line = reset_read_line(read_line);
	return (return_val);
}
