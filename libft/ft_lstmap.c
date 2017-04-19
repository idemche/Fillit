/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:40:34 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/27 13:27:53 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_node;
	t_list	*new_lst;

	new_lst = NULL;
	if (lst)
	{
		if ((new_lst = f(lst)) == NULL)
			return (NULL);
		new_node = new_lst;
		while (lst->next)
		{
			if ((new_node->next = f(lst->next)) == NULL)
				return (NULL);
			new_node = new_node->next;
			lst = lst->next;
		}
	}
	return (new_lst);
}
