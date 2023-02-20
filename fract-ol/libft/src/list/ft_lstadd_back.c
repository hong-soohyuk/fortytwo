/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:29:35 by soohong           #+#    #+#             */
/*   Updated: 2022/11/16 16:17:26 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	tail = *lst;
	while (tail->next)
		tail = tail->next;
	tail->next = new;
}
