/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:41:10 by soohong           #+#    #+#             */
/*   Updated: 2022/11/14 19:52:18 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*pointer;

	i = -1;
	pointer = (char *)s;
	while (pointer[++i])
		if (pointer[i] == c)
			return (pointer + i);
	if (c == '\0')
		return (pointer + i);
	else
		return (0);
}
