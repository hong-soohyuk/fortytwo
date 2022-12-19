/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:00:48 by soohong           #+#    #+#             */
/*   Updated: 2022/12/19 19:07:00 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_return(void *mem1, void *mem2)
{
	if (mem1)
	{
		free(mem1);
		mem1 = NULL;
	}
	if (mem2)
	{
		free(mem2);
		mem2 = NULL;
	}
	return (0);
}

size_t	gnl_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		s1_length;
	char	*result;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1)
			s1[0] = '\0';
		else
			return (0);
	}
	i = -1;
	s1_length = gnl_strlen(s1);
	result = (char *)malloc(sizeof(char) * (s1_length + gnl_strlen(s2) + 1));
	if (result == NULL)
		return (free_return(s1, NULL));
	while (s1[++i])
		result[i] = s1[i];
	i = -1;
	while (s2[++i])
		result[i + s1_length] = s2[i];
	result[i + s1_length] = '\0';
	free(s1);
	return (result);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

void	*gnl_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = b;
	i = 0;
	while (i < len)
		*(p + i++) = (unsigned char)c;
	return (b);
}
