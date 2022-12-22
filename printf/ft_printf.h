/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:07:34 by soohong           #+#    #+#             */
/*   Updated: 2022/12/21 14:51:12 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr_base(long long long_nbr, char *base);
int	ft_print_address(unsigned long long address);

#endif
