/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:56:37 by soohong           #+#    #+#             */
/*   Updated: 2023/02/03 23:22:13 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (lst == 0 || new_node == 0)
		return ;
	if (*lst)
		new_node->next = *lst;
	else
		new_node->next = 0;
	*lst = new_node;
}
