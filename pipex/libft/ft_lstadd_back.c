/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:29:35 by soohong           #+#    #+#             */
/*   Updated: 2023/02/03 23:22:09 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*tail;

	if (*lst == 0)
	{
		*lst = new_node;
		return ;
	}
	tail = *lst;
	while (tail->next)
		tail = tail->next;
	tail->next = new_node;
}
