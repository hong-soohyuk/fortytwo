/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:22:45 by soohong           #+#    #+#             */
/*   Updated: 2022/12/20 20:42:25 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (i);
}

static void	calc_base(long long nbr, long long length, char *base, int *len_printed)
{
	if (nbr >= length)
		calc_base(nbr / length, length, base, len_printed);
	*len_printed += write(1, &base[nbr % length], 1);
}

int	ft_putnbr_base(long long long_nbr, char *base)
{
	int	length;
	int	len_printed;

	len_printed = 0;
	length = base_check(base);
	if (length > 1)
	{
		if (long_nbr == 0)
			return (write(1, &base[0], 1));
		if (long_nbr < 0)
		{
			len_printed += write(1, "-", 1);
			long_nbr *= -1;
		}
		calc_base(long_nbr, (long long)length, base, &len_printed);
	}
	return (len_printed);
}
