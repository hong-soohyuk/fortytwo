/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:19:16 by soohong           #+#    #+#             */
/*   Updated: 2022/12/09 17:56:22 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_buffer(size_t buffer_size)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)malloc(sizeof(char) * buffer_size);
	if (result == NULL)
		return (0);
	while (i < buffer_size)
	{
		result[i] = 0;
		++i; 
	}
	result[i] = '\0';
	return (result);
}

static char	*terminate_safely()
{

	return (0);
}

static char	*split_newline(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != EOF)
		i++;
	return (gnl_strdup(&buff[i + 1]));
}

char	*get_next_line(int fd)
{
	static char	*prev_str;
	char 		*output;
	char		*buff;
	int			rd_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	output = prev_str;
	buff = init_buffer(BUFFER_SIZE + 1);
	rd_size = read(fd, buff, BUFFER_SIZE);
	while (!(gnl_strchr(buff, '\n')) && rd_size > 0)
	{
		output = gnl_strjoin(output, buff);
		rd_size = read(fd, buff, BUFFER_SIZE);
	}
	if (rd_size < 0)
		return (terminate_safely());
	prev_str = split_newline(buff);
	free(buff);
	return (output);
}

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("newfile", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	printf("Sentence: %s\n", line);
	line = get_next_line(fd);
	printf("Sentence: %s\n", line);
	line = get_next_line(fd);
	printf("Sentence: %s\n", line);
	line = get_next_line(fd);
	printf("Sentence: %s\n", line);
	line = get_next_line(fd);
	printf("Sentence: %s\n", line);
	free(line);
	close(fd);
	return (0);
}
