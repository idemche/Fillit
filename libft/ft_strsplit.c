/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:38:36 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 14:33:14 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_words(const char *s, char sep)
{
	int		i;
	int		flag;
	int		count;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] == sep)
			flag = 1;
		else if (s[i] != sep && flag == 1)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static char		*al_as(const char *s, unsigned int *k, char sep)
{
	unsigned int	pk;
	char			*ret;

	ret = 0;
	while (s[*k])
	{
		if (s[*k] == sep)
			(*k)++;
		else if (s[*k] != sep)
		{
			pk = *k;
			while (s[*k] != sep && s[*k])
				(*k)++;
			ret = ft_strsub(s, pk, (*k) - pk);
			break ;
		}
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**tab;
	int				i;
	unsigned int	k;
	int				wc;

	if (s == NULL)
		return (NULL);
	wc = count_words(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (wc + 1))) == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < wc)
	{
		tab[i] = al_as(s, &k, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
