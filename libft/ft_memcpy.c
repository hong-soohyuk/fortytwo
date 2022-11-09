/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:04:03 by soohong           #+#    #+#             */
/*   Updated: 2022/11/09 16:33:29 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*((char *)dst + i) = *((char *)src + i);
	return (dst);
}

#include <string.h>
#include <stdio.h>
int main(void)
{
	char target[] = "target";
	char source[] = "longlonglonglonglongsource";
	printf("%s", ft_memcpy(target, source, 7));
	//printf("%s", memcpy(target, source, 7));
	//printf("%s", memcpy(target, &target[2], 3));

}
