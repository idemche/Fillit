/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:01:46 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 17:56:33 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	len;
	int		i;
	int		k;
	int		j;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	k = len - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while ((s[k] == ' ' || s[k] == '\t' || s[k] == '\n') && k > 0)
		k--;
	if (k == 0 || s[i] == '\0')
		return (ft_strnew(0));
	if ((ret = (char *)malloc(sizeof(char) * (k - i + 2))) == NULL)
		return (NULL);
	j = 0;
	while (i <= k)
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}
