/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 01:18:59 by soohong           #+#    #+#             */
/*   Updated: 2022/11/11 01:31:22 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	int		i;

	string = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (string[i] == (unsigned char c))
			return (string + i);
	return (0);
}
