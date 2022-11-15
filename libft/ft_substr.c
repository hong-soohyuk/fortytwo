/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:22:09 by soohong           #+#    #+#             */
/*   Updated: 2022/11/13 18:27:13 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	substring = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (start[i] && i < len)
	{
		substring[i] = start[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
