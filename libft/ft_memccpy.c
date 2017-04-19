/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:29:49 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/28 17:25:59 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst8;
	char	*src8;

	dst8 = (char *)dst;
	src8 = (char *)src;
	while (n)
	{
		if ((*dst8++ = *src8++) == c)
			return (dst8);
		n--;
	}
	return (NULL);
}
