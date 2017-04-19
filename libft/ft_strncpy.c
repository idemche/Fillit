/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:26:38 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 19:02:25 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *s;

	s = dst;
	while (len > 0 && *src != 0)
	{
		*s++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*s++ = 0;
		len--;
	}
	return (dst);
}
