/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:46:58 by soohong           #+#    #+#             */
/*   Updated: 2023/01/13 15:45:28 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static int	ps_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ps_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

long	ps_atoi(const char *str)
{
	long	v;
	int		n;
	int		i;
	int		s;

	v = 0;
	i = 0;
	s = 1;
	while (ps_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	n = i;
	while (str[i] != '\0')
	{
		if (!ps_isdigit(str[i]))
			return (ATOI_FAILURE);
		v = (v * 10) + (str[i++] - '0');
	}
	v = (int)(v * s);
	if ((s > 0 && v < 0) || (s < 0 && v > 0) || i - n > 10 || !(i - n))
		return (ATOI_FAILURE);
	return ((int)v);
}
