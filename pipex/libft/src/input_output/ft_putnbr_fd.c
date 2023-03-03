/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:13:57 by soohong           #+#    #+#             */
/*   Updated: 2023/02/20 17:19:37 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	digit_count(int n)
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

static void	make_output(char result[], int n, int fd, int count)
{
	int	i;

	i = count;
	while (--i > -1)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
	}
	write(fd, result, count);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	result[10];

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	make_output(result, n, fd, digit_count(n));
}
