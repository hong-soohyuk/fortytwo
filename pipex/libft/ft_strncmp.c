/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:52:50 by soohong           #+#    #+#             */
/*   Updated: 2022/11/11 14:27:03 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*uns1;
	unsigned char	*uns2;

	uns1 = (unsigned char *)s1;
	uns2 = (unsigned char *)s2;
	while (*uns1 != '\0' && *uns2 != '\0' && n > 0)
	{
		if (*uns1 != *uns2)
			break ;
		uns1++;
		uns2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*uns1 - *uns2);
}
