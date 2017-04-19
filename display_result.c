/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:54:37 by araichyn          #+#    #+#             */
/*   Updated: 2016/12/06 14:50:39 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display_sq(char *res, int sq_size)
{
	int		i;
	int		k;

	i = 0;
	while (i < sq_size)
	{
		k = 0;
		while (k < sq_size)
		{
			if (res[i * sq_size + k] == 0)
				ft_putchar('.');
			else
				ft_putchar(res[i * sq_size + k]);
			k++;
		}
		ft_putchar('\n');
		i++;
	}
}
