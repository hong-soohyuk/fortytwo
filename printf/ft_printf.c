/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:37:03 by soohong           #+#    #+#             */
/*   Updated: 2022/12/22 18:34:57 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_by_format(va_list arg_pointer, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg_pointer, int)));
	else if (format == 's')
		return ((ft_putstr(va_arg(arg_pointer, char *))));
	else if (format == 'p')
		return (ft_print_address(
				(unsigned long long)va_arg(arg_pointer, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(arg_pointer, int), "0123456789"));
	else if (format == 'u')
		return (ft_putnbr_base(
				(long long)va_arg(arg_pointer, unsigned int),
				"0123456789"));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(arg_pointer, unsigned int),
				"0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(arg_pointer, unsigned int),
				"0123456789ABCDEF"));
	else if (format == '%')
		return (write(1, &"%", 1));
	return (-1);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg_pointer;
	int		len_printed;
	int		i;
	int		return_val;

	va_start(arg_pointer, string);
	len_printed = 0;
	i = -1;
	while (string[++i])
	{
		if (string[i] != '%')
			return_val = write(1, &string[i], 1);
		else
			return_val = print_by_format(arg_pointer, string[(i++) + 1]);
		if (return_val == -1)
		{
			va_end(arg_pointer);
			return (-1);
		}
		len_printed += return_val;
	}
	va_end(arg_pointer);
	return (len_printed);
}
