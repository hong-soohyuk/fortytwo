/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:22:45 by soohong           #+#    #+#             */
/*   Updated: 2022/12/21 14:38:11 by soohong          ###   ########.fr       */
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

static void	calc_base(unsigned long long nbr, int len, char *b, int *len_p)
{
	unsigned long long	ull;

	ull = (unsigned long long)len;
	if (nbr >= ull)
		calc_base(nbr / ull, len, b, len_p);
	*len_p += write(1, &b[nbr % ull], 1);
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
		calc_base(long_nbr, length, base, &len_printed);
	}
	return (len_printed);
}

int	ft_print_address(unsigned long long address)
{
	int	len_printed;

	len_printed = ft_putstr("0x");
	if (address == 0)
		return (len_printed + write(1, &"0", 1));
	calc_base(address, 16, "0123456789abcdef", &len_printed);
	return (len_printed);
}
