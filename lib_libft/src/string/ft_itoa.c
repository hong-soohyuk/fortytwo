/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:12 by soohong           #+#    #+#             */
/*   Updated: 2023/02/20 17:19:12 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	digit_count(long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static	void	num_to_string(char *result, int start, int max_i, long long n)
{
	int	digit;
	int	i;

	i = max_i - 1;
	if (n == 0)
		result[0] = '0';
	while (n > 0 && i >= start)
	{
		digit = (int)(n % 10);
		n /= 10;
		result[i] = digit + '0';
		i--;
	}
	result[max_i] = '\0';
}

char	*ft_itoa(int n)
{
	char		*result;
	long long	value;
	int			negative;
	int			max_index;

	value = (long long)n;
	max_index = 0;
	negative = 0;
	if (value < 0)
	{
		negative = 1;
		value *= -1;
		max_index++;
	}
	max_index += digit_count(value);
	result = (char *)malloc(sizeof(char) * max_index + 1);
	if (result == 0)
		return (0);
	if (negative)
	{
		result[0] = '-';
		num_to_string(result, 1, max_index, value);
	}
	num_to_string(result, 0, max_index, value);
	return (result);
}
