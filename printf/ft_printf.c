/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:37:03 by soohong           #+#    #+#             */
/*   Updated: 2022/12/21 14:38:24 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_by_format(va_list arg_pointer, char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(arg_pointer, int));
	else if (format == 's')
		length += (ft_putstr(va_arg(arg_pointer, char *)));
	else if (format == 'p')
		length += ft_print_address(
				(unsigned long long)va_arg(arg_pointer, void *));
	else if (format == 'd' || format == 'i')
		length += (ft_putnbr_base(va_arg(arg_pointer, int), "0123456789"));
	else if (format == 'u')
		length += (ft_putnbr_base(
					(long long)va_arg(arg_pointer, unsigned int),
					"0123456789"));
	else if (format == 'x')
		length += (ft_putnbr_base(va_arg(arg_pointer, unsigned int),
					"0123456789abcdef"));
	else if (format == 'X')
		length += (ft_putnbr_base(va_arg(arg_pointer, unsigned int),
					"0123456789ABCDEF"));
	else if (format == '%')
		length += (write(1, &"%", 1));
	return (length);
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
