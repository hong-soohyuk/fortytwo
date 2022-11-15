/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:32:14 by soohong           #+#    #+#             */
/*   Updated: 2022/11/15 19:06:01 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	int		i;
	char	*duplicate;

	length = ft_strlen(s1);
	i = -1;
	duplicate = (char *)malloc(sizeof(char) * (length + 1));
	if (duplicate == 0)
		return (0);
	while (s1[++i])
		duplicate[i] = s1[i];
	duplicate[i] = '\0';
	return (duplicate);
}
