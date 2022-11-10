/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:30:36 by soohong           #+#    #+#             */
/*   Updated: 2022/11/10 21:37:00 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		i = -1;
		while (++i < len)
			*((char *)dst + i) = *((char *)src + i);
	}
	else
	{
		i = len;
		while (i > 0)
		{
			*((char *)dst + (i - 1)) = *((char *)src + (i - 1));
			--i;
		}
	}
	return (dst);
}
