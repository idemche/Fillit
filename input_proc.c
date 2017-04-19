/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:07:36 by araichyn          #+#    #+#             */
/*   Updated: 2016/12/06 13:48:11 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_tmino(char *b)
{
	int		i;

	i = 0;
	while (i < NUM_SHAPES)
	{
		if (ft_strncmp(g_arr[i], b, 16) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		check_block(char *b)
{
	int		i;

	i = 0;
	while (i < BLK_SZ)
	{
		if (((i + 1) % 5 == 0))
		{
			if (b[i] != '\n')
				return (ft_puterr("error\n"));
		}
		else if (b[i] == C_ETY || b[i] == C_FLL)
			;
		else
			return (ft_puterr("error\n"));
		i++;
	}
	return (0);
}

t_tmino	*build_tmino(char *buffer)
{
	t_tmino	*ret;
	int		i;

	if ((ret = (t_tmino*)malloc(sizeof(*ret))) == NULL)
		return (NULL);
	ret->width = 0;
	ret->height = 0;
	ret->map = ft_strdup(buffer);
	i = 0;
	while (i < 16)
	{
		if (buffer[i] == C_FLL)
		{
			if (i % 4 > ret->width - 1)
				ret->width = (i % 4) + 1;
			if (i / 4 > ret->height - 1)
				ret->height = (i / 4) + 1;
		}
		i++;
	}
	return (ret);
}

char	*strip_nl(char *s)
{
	char	**tab;
	char	*ret;
	int		i;
	int		k;

	if ((tab = ft_strsplit(s, '\n')) == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	ret = tab[0];
	k = 0;
	while (++k < i)
		ret = ft_strjoin(ret, tab[k]);
	return (ret);
}

char	*norm_shape(char *buffer)
{
	int		i;
	int		minx;
	int		miny;

	i = 0;
	minx = 3;
	miny = 3;
	while (i < 16)
	{
		if (buffer[i] == C_FLL)
		{
			if (i % 4 < minx)
				minx = i % 4;
			if (i / 4 < miny)
				miny = i / 4;
		}
		i++;
	}
	return (ft_strshift(buffer, (-(miny * 4) - minx)));
}
