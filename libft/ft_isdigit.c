/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:12:06 by soohong           #+#    #+#             */
/*   Updated: 2022/11/08 22:32:40 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	unsigned char	digit;

	digit = (unsigned char)c;
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}
