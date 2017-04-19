/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:51:05 by araichyn          #+#    #+#             */
/*   Updated: 2016/12/06 12:38:22 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char *s, int n)
{
	size_t	len;
	int		shift;
	char	*s_over;
	char	*s_shift;

	if (n == 0)
		return (s);
	len = ft_strlen(s);
	shift = (n < 0) ? (len - (-n % len)) : (n % len);
	s_over = ft_strsub(s, len - shift, shift);
	s_shift = ft_strsub(s, 0, len - shift);
	return (ft_strjoin(s_over, s_shift));
}
