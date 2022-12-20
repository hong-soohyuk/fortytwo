/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:50:21 by soohong           #+#    #+#             */
/*   Updated: 2022/12/20 20:43:43 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	ft_putstr(char *s)
{
	int	length;

	length = (int)ft_strlen(s);
	write(1, s, length);
	return (length);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
