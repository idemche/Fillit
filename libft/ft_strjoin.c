/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:19:44 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 14:39:04 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	size_t			len1;
	size_t			len2;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((ret = (char *)malloc(len1 + len2 + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		ret[len1 + i] = s2[i];
		i++;
	}
	ret[len1 + len2] = 0;
	return (ret);
}
