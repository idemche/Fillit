/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:28:27 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/22 15:53:29 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	cpy_len;

	dest_len = ft_strlen(s1);
	src_len = ft_strlen(s2);
	cpy_len = (src_len < n) ? src_len : n;
	ft_memcpy(s1 + dest_len, s2, cpy_len);
	s1[dest_len + cpy_len] = '\0';
	return (s1);
}
