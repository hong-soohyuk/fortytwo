/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:27:26 by soohong           #+#    #+#             */
/*   Updated: 2022/11/13 18:40:02 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	s1_length;
	int	s2_length;
	char	*result;

	i = -1;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_length + s2_lenght + 1));
	if (!result)
		return (0);
	while (s1[++i])
		result[i] = s1[i];
	i = -1;
	while (s2[++i])
		result[i + s1_length] = s2[i];
	result[i] = '\0';
	return (result);
}
