/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:45:13 by soohong           #+#    #+#             */
/*   Updated: 2023/02/20 17:19:12 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_left(char const *s1, char const *set)
{
	int	i;

	i = -1;
	while (s1[++i])
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
	return (-1);
}

static int	ft_right(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (--i > -1)
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		left;
	int		right;
	char	*result;
	int		i;

	left = ft_left(s1, set);
	right = ft_right(s1, set);
	i = 0;
	if (left == -1 || right == -1)
	{
		result = (char *)malloc(1);
		if (result == 0)
			return (0);
		result[0] = '\0';
		return (result);
	}
	result = (char *)malloc(sizeof(char) * (right - left + 2));
	if (!result)
		return (0);
	while (left <= right)
		result[i++] = s1[left++];
	result[i] = '\0';
	return (result);
}
