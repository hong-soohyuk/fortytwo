/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:24:03 by soohong           #+#    #+#             */
/*   Updated: 2022/12/13 17:11:29 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_length;
	int		s2_length;
	char	*result;

	if (s1 == NULL)
		return (gnl_strdup(s2));
	i = -1;
	s1_length = gnl_strlen(s1);
	s2_length = gnl_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_length + s2_length + 1));
	if (result == NULL)
		return (0);
	while (s1[++i])
		result[i] = s1[i];
	i = -1;
	while (s2[++i])
		result[i + s1_length] = s2[i];
	result[i + s1_length] = '\0';
	return (result);
}

char	*gnl_strdup(const char *s1)
{
	int		length;
	int		i;
	char	*duplicate;

	length = gnl_strlen(s1);
	i = -1;
	duplicate = (char *)malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (0);
	while (s1[++i])
		duplicate[i] = s1[i];
	duplicate[i] = '\0';
	return (duplicate);
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
