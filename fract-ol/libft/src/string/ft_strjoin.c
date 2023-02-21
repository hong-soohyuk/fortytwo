/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:27:26 by soohong           #+#    #+#             */
/*   Updated: 2023/02/20 17:19:12 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_length;
	int		s2_length;
	char	*result;

	i = -1;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_length + s2_length + 1));
	if (result == 0)
		return (0);
	while (s1[++i])
		result[i] = s1[i];
	i = -1;
	while (s2[++i])
		result[i + s1_length] = s2[i];
	result[i + s1_length] = '\0';
	return (result);
}
