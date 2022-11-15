/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:22:09 by soohong           #+#    #+#             */
/*   Updated: 2022/11/15 19:02:49 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	int		i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substring = (char *)malloc(1);
		if (substring == 0)
			return (0);
		substring[0] = '\0';
		return (substring);
	}
	if (s_len < start + len)
		len = s_len - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (substring == 0)
		return (0);
	i = -1;
	while (++i < (int)len)
		substring[i] = s[start + i];
	substring[i] = '\0';
	return (substring);
}
