/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:47:30 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 12:08:57 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_table(char **table, int size)
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
			return (free_table(table, table_i));
		else
			fill_element(table[table_i], &str[start], (str_i - start));
		table_i++;
	}
	table[table_i] = 0;
	return (1);
}

char	**ps_split(char const *s, char c)
{
	char	**table;
	char	*str;
	int		size;

	str = (char *)s;
	while (*str == c && *str)
		str++;
	size = size_of_table(str, c);
	table = (char **)malloc(sizeof(char *) * (size + 1));
	if (table && fill_table(table, str, c, size))
		return (table);
	else
		return (0);
}
