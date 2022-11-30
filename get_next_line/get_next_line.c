/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:27:15 by soohong           #+#    #+#             */
/*   Updated: 2022/11/30 13:58:43 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	initialize_buffer(char *buff, int value, size_t buffer_size)
{
	size_t	i;

	i = 0;
	while (i < buffer_size)
	{
		buff[i] = value;
		++i;
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];

	initialize_buffer(buff, 0, BUFFER_SIZE + 1);
	read(fd, buff, length);
	buff[length] = '\0';
	return (buff);
}


int	main(void)
{
	int		fd;
	char	*result;
	
	fd = open("./newfile", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
}
