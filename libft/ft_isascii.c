/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:37:17 by soohong           #+#    #+#             */
/*   Updated: 2022/11/11 12:18:07 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	unsigned char	ascii;

	ascii = (unsigned char)c;
	if (ascii >= 0 && ascii <= 127)
		return (1);
	else
		return (0);
}
