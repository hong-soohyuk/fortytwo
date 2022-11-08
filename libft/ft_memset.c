/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:18:17 by soohong           #+#    #+#             */
/*   Updated: 2022/11/08 22:43:27 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = b;
	while (--len)
		*p++ = (unsigned char)c;
	return (b);
}

#include <stdio.h>
int	main(void)
{
	char string[] = "hello";
	printf("%s", ft_memset(string, 'A', 2));
}
