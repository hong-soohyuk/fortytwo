/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 01:26:04 by soohong           #+#    #+#             */
/*   Updated: 2022/11/11 01:33:32 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int		i;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (string1[i] != string[i])
			return (string1[i] - string2[i]);
	return (0);
}
