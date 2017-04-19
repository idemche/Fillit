/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:55:14 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/27 14:56:38 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		k;
	int		found;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
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
			if (found)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
