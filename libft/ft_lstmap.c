/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:18:33 by soohong           #+#    #+#             */
/*   Updated: 2022/11/16 17:28:38 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	head = 0;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	new_node = 0;
	return (head);
}
