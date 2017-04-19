/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:13:03 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/22 15:47:34 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(s1);
	src_len = ft_strlen(s2);
	ft_memcpy(s1 + dest_len, s2, src_len + 1);
	return (s1);
}
