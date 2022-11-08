/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:14:57 by soohong           #+#    #+#             */
/*   Updated: 2022/11/08 21:33:54 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalnum(int c)
{
	unsigned char	alnum;

	alnum = (unsigned char)c;
	if ((alnum >= '0' && alnum <= '9') || (alnum >= 'A' && alnum <= 'Z')
		|| (alnum >= 'a' && alnum <= 'z'))
		return (1);
	else
		return (0);
}
