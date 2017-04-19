/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:52:58 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/19 18:53:00 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	g_print_char = '@';

char	*pack_shapes(t_tmino **tmino_arr, int *sz_p)
{
	char	*res;
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (tmino_arr[num])
		num++;
	*sz_p = ft_fssq(num * 4);
	if ((res = ft_strnew((*sz_p) * (*sz_p))) == NULL)
		return (NULL);
	while (!find_solution(tmino_arr, &res, 0, *sz_p))
	{
		(*sz_p)++;
		if ((res = ft_strnew((*sz_p) * (*sz_p))) == NULL)
			return (NULL);
	}
	return (res);
}

int		find_solution(t_tmino **tmino_arr, char **field, int level, int sq_size)
{
	int		i;
	int		end;

	if (!tmino_arr[level])
		return (1);
	i = 0;
	end = (sq_size * sq_size) - ((tmino_arr[level]->height - 1) * sq_size) -
		(tmino_arr[level]->width - 1);
	g_print_char++;
	while (i < end)
	{
		if (place_tmino(tmino_arr[level], field, sq_size, i))
		{
			if (find_solution(tmino_arr, field, level + 1, sq_size))
				return (1);
			else
				remove_tmino(tmino_arr[level], field, sq_size, i);
		}
		i++;
	}
	g_print_char--;
	return (0);
}

int		place_tmino(t_tmino *tmino, char **field, int sq_size, int i)
{
	int		k;
	int		j;

	if ((i % sq_size) + (tmino->width - 1) >= sq_size)
		return (0);
	if ((i / sq_size) + (tmino->height - 1) >= sq_size)
		return (0);
	if (!check_place(tmino, field, sq_size, i))
		return (0);
	k = 0;
	while (k < tmino->height)
	{
		j = 0;
		while (j < tmino->width)
		{
			if (tmino->map[k * 4 + j] == C_FLL)
				(*field)[i + (k * sq_size) + j] = g_print_char;
			j++;
		}
		k++;
	}
	return (1);
}

int		check_place(t_tmino *tmino, char **field, int sq_size, int i)
{
	int		k;
	int		j;

	k = 0;
	while (k < tmino->height)
	{
		j = 0;
		while (j < tmino->width)
		{
			if (tmino->map[k * 4 + j] == C_FLL)
				if ((*field)[i + (k * sq_size) + j])
					return (0);
			j++;
		}
		k++;
	}
	return (1);
}

void	remove_tmino(t_tmino *tmino, char **field, int sq_size, int i)
{
	int		k;
	int		j;

	k = 0;
	while (k < tmino->height)
	{
		j = 0;
		while (j < tmino->width)
		{
			if (tmino->map[k * 4 + j] == C_FLL)
				(*field)[i + (k * sq_size) + j] = 0;
			j++;
		}
		k++;
	}
}
