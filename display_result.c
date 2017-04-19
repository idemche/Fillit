/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:51:50 by idemchen          #+#    #+#             */
/*   Updated: 2017/04/19 18:51:53 by idemchen         ###   ########.fr       */
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
