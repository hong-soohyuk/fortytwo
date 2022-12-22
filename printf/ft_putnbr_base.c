/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:22:45 by soohong           #+#    #+#             */
/*   Updated: 2022/12/22 18:34:03 by soohong          ###   ########.fr       */
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

static int	calc_base(unsigned long long nbr, int len, char *b, int *len_p)
{
	unsigned long long	ull;
	int					write_val;

	ull = (unsigned long long)len;
	write_val = 0;
	if (nbr >= ull)
		write_val = calc_base(nbr / ull, len, b, len_p);
	if (write_val == -1)
		return (-1);
	return (write_val + write(1, &b[nbr % ull], 1));
}

int	ft_putnbr_base(long long long_nbr, char *base)
{
	int	length;
	int	len_sign;
	int	len_printed;

	len_sign = 0;
	len_printed = 0;
	length = base_check(base);
	if (length > 1)
	{
		if (long_nbr == 0)
			return (write(1, &base[0], 1));
		if (long_nbr < 0)
		{
			len_sign = write(1, "-", 1);
			if (len_sign == -1)
				return (-1);
			long_nbr *= -1;
		}
		len_printed = calc_base(long_nbr, length, base, &len_printed);
	}
	if (len_printed == -1)
		return (-1);
	else
		return (len_sign + len_printed);
}

int	ft_print_address(unsigned long long address)
{
	int	len_printed;

	len_printed = ft_putstr("0x");
	if (len_printed == -1)
		return (-1);
	if (address == 0)
	{
		if (write(1, &"0", 1) == -1)
			return (-1);
		else
			return (3);
	}
	len_printed = calc_base(address, 16, "0123456789abcdef", &len_printed);
	if (len_printed == -1)
		return (-1);
	else
		return (2 + len_printed);
}
