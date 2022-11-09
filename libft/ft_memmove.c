/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:30:36 by soohong           #+#    #+#             */
/*   Updated: 2022/11/09 18:27:37 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src || len == 0)
		return dst;
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

#include <string.h>
int main(void)
{
	char target[] = "0123456789";
	char source[] = "longlonglonglonglongsource";
	printf("%s", ft_memmove(&target[2], target, 3));
	//printf("%s", memmove(&target[2], target, 3));
	//printf("%s", ft_memmove(target, &target[2], 3));
	//printf("%s", memmove(target, &target[2], 3));

}
