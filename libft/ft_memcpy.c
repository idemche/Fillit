/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:29:29 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/28 16:53:47 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst8;
	unsigned char	*src8;

	dst8 = (unsigned char *)dst;
	src8 = (unsigned char *)src;
	while (n > 0)
	{
		*dst8++ = *src8++;
		n--;
	}
	return (dst);
}
