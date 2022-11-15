/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:05:49 by soohong           #+#    #+#             */
/*   Updated: 2022/11/15 19:00:44 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	finalize_safely(char **table, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(table[i]);
	free(table);
	return (0);
}

static int	size_of_table(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (i == 0 || (str[i] != c && str[i - 1] == c))
			count++;
	return (count);
}

static void	fill_element(char *dst, char *src, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		dst[i] = src[i];
	dst[i] = '\0';
}

static int	fill_table(char **table, char *str, char c, int table_size)
{
	int	start;
	int	str_i;
	int	table_i;

	str_i = 0;
	table_i = 0;
	while (str[str_i] && table_i < table_size)
	{
		while (str[str_i] == c && str[str_i])
			str_i++;
		start = str_i;
		while (str[str_i] != c && str[str_i])
			str_i++;
		table[table_i] = malloc(sizeof(char) * (str_i - start + 1));
		if (table[table_i] == 0)
			return (finalize_safely(table, table_i));
		else
			fill_element(table[table_i], &str[start], (str_i - start));
		table_i++;
	}
	table[table_i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	char	*str;
	int		size;

	str = (char *)s;
	while (*str == c && *str)
		str++;
	size = size_of_table(str, c);
	table = (char **)malloc(sizeof(char *) * (size + 1));
	if (table == 0)
		return (0);
	if (fill_table(table, str, c, size) == 0)
		return (0);
	else
		return (table);
}
