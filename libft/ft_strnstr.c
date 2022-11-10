/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 01:35:30 by soohong           #+#    #+#             */
/*   Updated: 2022/11/11 02:20:24 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay_pointer;
	size_t	length_left;
	size_t	needle_length;
	size_t	i;

	hay_pointer = (char *)haystack;
	if (*needle = '\0')
		return (haystack);
	length_left = len;
	needle_len = ft_strlen(needle);
	while (*hay_pointer && length_left >= needle_len)
	{
		if (*hay_pointer == *needle
			&& ft_strncmp(needle, hay_pointer, needle_len) == 0)
			return (hay_pointer);
		hay_pointer++;
		length_left__;
	}
	return (0);
}
