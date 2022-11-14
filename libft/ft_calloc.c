/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:26:25 by soohong           #+#    #+#             */
/*   Updated: 2022/11/14 14:40:24 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*address;
	if (size && count > SIZE_MAX / size)
		return (0);
	address = malloc(count * size);
	if (address == 0)
		return (0);
	ft_memset(address, 0, count * size);
	return (address);
}
