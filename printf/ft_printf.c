/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:37:03 by soohong           #+#    #+#             */
/*   Updated: 2022/12/20 20:48:56 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_by_format(va_list arg_pointer, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg_pointer, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg_pointer, char *)));
	else if (format == 'p')
		return (0);
	else if (format == 'd')
		return (ft_putnbr_base(va_arg(arg_pointer, int), "0123456789"));
	else if (format == 'i')
		return (ft_putnbr_base(va_arg(arg_pointer, int), "0123456789"));
	else if (format == 'u')
		return (ft_putnbr_base((long long)va_arg(arg_pointer, unsigned int), "0123456789"));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(arg_pointer, int), "0123456789"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(arg_pointer, int), "0123456789"));
	else if (format == '%')
		return (write(1, &"%", 1));
	else
		return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg_pointer;
	int		len_printed;
	int		i;

	i = -1;
	len_printed = 0;
	va_start(arg_pointer, string);
	while (string[++i])
	{
		if (string[i] != '%')
			len_printed += write(1, &string[i], 1);
		else
		{
			len_printed += print_by_format(arg_pointer, string[i + 1]);
			++i;
		}
	}
	va_end(arg_pointer);
	return (len_printed);
}

#include <stdio.h>

int main ()
{
	unsigned int i = 4294967295;
	unsigned int j = 1;
	ft_printf("mine:	%u\n", j);
	printf("printf:	%u\n", i);
	return(0);

}
