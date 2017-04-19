/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:06:15 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 19:26:11 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*tmp;

	if (alst && *alst)
	{
		lst = *alst;
		while (lst)
		{
			tmp = lst->next;
			if (del)
				del(lst->content, lst->content_size);
			free(lst);
			lst = tmp;
		}
		*alst = NULL;
	}
}
