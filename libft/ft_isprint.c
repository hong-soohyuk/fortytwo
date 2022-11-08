/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:00:54 by soohong           #+#    #+#             */
/*   Updated: 2022/11/08 22:13:23 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isprint(int c)
{
	unsigned char	print;

	print = (unsigned char) c;
	if ((print >= 040 && print <= 077) || (print >= 100 && print <= 176))
		return (1);
	else
		return (0);
}
