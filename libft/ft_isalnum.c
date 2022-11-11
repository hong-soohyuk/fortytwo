/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:14:57 by soohong           #+#    #+#             */
/*   Updated: 2022/11/11 15:04:10 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	alnum;

	alnum = (unsigned char)c;
	if (ft_isdigit(alnum) || ft_isalpha(alnum))
		return (1);
	else
		return (0);
}
