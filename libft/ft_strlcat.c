/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:58:04 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 12:29:41 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		dlen;
	int		free_len;
	int		slen;
	char	*dend;
	int		i;

	dlen = ft_strlen(dst);
	free_len = size - dlen - 1;
	slen = ft_strlen(src);
	dend = dst + dlen;
	i = 0;
	while (i < free_len && src[i] != '\0')
	{
		dend[i] = src[i];
		i++;
	}
	dend[i] = '\0';
	return (((dlen < (int)size) ? dlen : size) + slen);
}
