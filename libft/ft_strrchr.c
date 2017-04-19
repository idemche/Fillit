/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:21:13 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/27 12:15:17 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		end;
	char	ch;
	char	*ret;

	end = 0;
	ch = c;
	ret = NULL;
	while (1)
	{
		if (*s == ch)
			ret = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (ret);
}
