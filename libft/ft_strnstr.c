/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:56:11 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/29 11:59:05 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	k;
	int				found;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			k = 0;
			found = 1;
			while (little[k] && found)
			{
				if (big[i + k] != little[k])
					found = 0;
				k++;
			}
			if (found && (i + k) <= len)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
