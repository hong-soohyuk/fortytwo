/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:44:32 by soohong           #+#    #+#             */
/*   Updated: 2022/11/14 14:43:13 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	int		i;
	char	*pointer;

	i = ft_strlen(s);
	pointer = (char *)s;
	if (c == '\0')
		return (pointer + i);
	while (--i > -1)
		if (pointer[i] == c)
			return (pointer + i);
	return (0);
}
