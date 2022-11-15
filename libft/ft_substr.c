/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:22:09 by soohong           #+#    #+#             */
/*   Updated: 2022/11/15 18:15:08 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		substring = (char *)malloc(1);
		if (substring == 0)
			return (0);
		substring[0] = '\0';
		return (substring);
	}
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (substring == 0)
		return (0);
	i = 0;
	while (i < len &&s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
