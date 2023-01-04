/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:43:05 by soohong           #+#    #+#             */
/*   Updated: 2023/01/03 17:43:06 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ps_atoi(const char *str)
{
	long	value;
	int		int_value;
	int		i;
	int		sign;

	value = 0;
	i = 0;
	sign = 1;
	while (ps_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ps_isdigit(str[i]))
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	int_value = (int)(value * sign);
	if (sign > 0 && int_value < 0 || sign < 0 && int_value > 0)
		return (-1);
	else
		return ((int)value);
}
