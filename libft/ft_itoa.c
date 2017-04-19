/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:50:45 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 19:01:32 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*build_str(int *darr, int i, int neg)
{
	int		j;
	char	*ret;

	if (i == 0)
	{
		if ((ret = (char *)ft_memalloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		ret[0] = '0';
		return (ret);
	}
	if ((ret = (char *)malloc(sizeof(char) * (i + neg + 1))) == NULL)
		return (NULL);
	j = 0;
	if (neg)
		ret[j++] = '-';
	while (j < i + neg)
	{
		ret[j] = darr[i - 1 - j + neg] + '0';
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char		*ft_itoa(int n)
{
	unsigned int	num;
	int				neg;
	int				darr[10];
	int				i;

	num = (n >= 0) ? n : -n;
	neg = (n >= 0) ? 0 : 1;
	i = 0;
	while (num)
	{
		darr[i++] = num % 10;
		num /= 10;
	}
	return (build_str(darr, i, neg));
}
